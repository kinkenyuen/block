//
//  ViewController.m
//  block
//
//  Created by kinken on 2020/6/17.
//  Copyright © 2020 kinken. All rights reserved.
//

#import "ViewController.h"

//情况1 block定义在全局区域
void(^block)(void) = ^(void) {
    NSLog(@"global block");
};

//全局变量
int global_val = 1;
static int static_global_val = 2;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //情况2 不捕获自动变量
//    void(^block)(void) = ^(void) {
//        NSLog(@"block invoked");
//    };
    
//    void(^block)(void) = ^(void) {
//        NSLog(@"block invoked");
//        NSLog(@"global_val : %d", global_val);
//        NSLog(@"static_global_val : %d", static_global_val);
//    };
    
    //静态局部变量
    static int static_val = 2;
    void(^block)(void) = ^(void) {
        NSLog(@"block invoked");
        NSLog(@"static_val : %d", static_val);
    };
    
    block();
}


@end
