//
//  ViewController.m
//  block
//
//  Created by kinken on 2020/6/17.
//  Copyright © 2020 kinken. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    int val = 1;
    //在栈上生成的block,并且捕获自动变量,为__NSStackBlock__
    NSLog(@"%@",^{NSLog(@"val : %d",val);});
}

@end
