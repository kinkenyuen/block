//
//  ViewController.m
//  block
//
//  Created by kinken on 2020/6/17.
//  Copyright © 2020 kinken. All rights reserved.
//

#import "ViewController.h"

typedef void(^blk_t)(void);

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //情况1 block中捕获使用局部变量
    //大多数情况下编译器做了判断，自动插入copy的代码将__NSStackBlock__变成__NSMallocBlock__
    int val = 1;
    void(^block)(void) = ^(void) {
        NSLog(@"block invoked");
        NSLog(@"val : %d", val);
    };
    NSLog(@"block : %@",block);
    
    //在栈上生成的block并且捕获自动变量,为__NSStackBlock__
    NSLog(@"%@",^{NSLog(@"val : %d",val);});
    
    //情况2 对__NSStackBlock__进行copy操作后，成为__NSMallocBlock__
    NSLog(@"%@",[^{NSLog(@"val : %d",val);} copy]);
}

@end
