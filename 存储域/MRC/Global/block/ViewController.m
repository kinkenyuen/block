//
//  ViewController.m
//  block
//
//  Created by kinken on 2020/6/17.
//  Copyright © 2020 kinken. All rights reserved.
//

#import "ViewController.h"

void(^global_Block)(void) = ^(void) {
};

int global_val = 1;
static int static_global_val = 2;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //情况1 block定义在全局区
    NSLog(@"%@",global_Block);

    //情况2 block没有捕获自动变量
    int val = 1;
    static int static_val = 2;
    void(^block)(void) = ^(void) {
        NSLog(@"global_val : %d",global_val);
        NSLog(@"static_global_val : %d",static_global_val);
        NSLog(@"static_val : %d",static_val);
    };
    NSLog(@"%@",block);
    
}

@end
