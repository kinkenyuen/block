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
    
    //block捕获了自动变量，手动调用copy方法
    int val = 1;
    NSLog(@"%@",[^{NSLog(@"val : %d",val);} copy]);
}

@end
