// 为每个__block变量生成新的结构体类型
struct __Block_byref_a_0 {
  void *__isa;
__Block_byref_a_0 *__forwarding;// 指向自身
 int __flags;
 int __size;
 int a;// 保存__block变量的值
};

struct __Block_byref_b_1 {
  void *__isa;
__Block_byref_b_1 *__forwarding;
 int __flags;
 int __size;
 int b;
};

struct __main_block_impl_0 {
  struct __block_impl impl;
  struct __main_block_desc_0* Desc;
  __Block_byref_a_0 *a; // by ref // 引用__block变量结构体指针
  __Block_byref_b_1 *b; // by ref // 引用__block变量结构体指针
    // 结构体构造函数
  __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, __Block_byref_a_0 *_a, __Block_byref_b_1 *_b, int flags=0) : a(_a->__forwarding), b(_b->__forwarding) {
    impl.isa = &_NSConcreteStackBlock; // block类型
    impl.Flags = flags;
    impl.FuncPtr = fp;// 函数指针，对应block块代码那部分
    Desc = desc;
  }
};

// block块代码对应的c函数
static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
  __Block_byref_a_0 *a = __cself->a; // bound by ref
  __Block_byref_b_1 *b = __cself->b; // bound by ref

        (a->__forwarding->a) = 20;
        (b->__forwarding->b) = 30;
        printf("inblock : a = %d, b = %d\n",(a->__forwarding->a), (b->__forwarding->b));
    }

// 对引用类型 计数+1 相当于retain
static void __main_block_copy_0(struct __main_block_impl_0*dst, struct __main_block_impl_0*src) {_Block_object_assign((void*)&dst->a, (void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);_Block_object_assign((void*)&dst->b, (void*)src->b, 8/*BLOCK_FIELD_IS_BYREF*/);}

// 对引用类型 计数-1 相当于release
static void __main_block_dispose_0(struct __main_block_impl_0*src) {_Block_object_dispose((void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);_Block_object_dispose((void*)src->b, 8/*BLOCK_FIELD_IS_BYREF*/);}

// 结构体信息描述类型的一个结构体
static struct __main_block_desc_0 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __main_block_impl_0*, struct __main_block_impl_0*);
  void (*dispose)(struct __main_block_impl_0*);
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0), __main_block_copy_0, __main_block_dispose_0};

int main(int argc, const char * argv[]) {
    // __block变量a 结构体的初始化 特别注意&a(指向自身)
    __attribute__((__blocks__(byref))) __Block_byref_a_0 a = {(void*)0,(__Block_byref_a_0 *)&a, 0, sizeof(__Block_byref_a_0), 10};
    
__Block_byref_b_1 b = {(void*)0,(__Block_byref_b_1 *)&b, 0, sizeof(__Block_byref_b_1), 20};

    // 初始化block结构体，并将block结构体的指针(内存地址)赋值给myLocalBlock
    void (*myLocalBlock)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, (__Block_byref_a_0 *)&a, (__Block_byref_b_1 *)&b, 570425344));

    // 调用block 并将myLocalBlock结构体指针传入
    ((void (*)(__block_impl *))((__block_impl *)myLocalBlock)->FuncPtr)((__block_impl *)myLocalBlock);

    printf("outblock : a = %d, b = %d\n",(a.__forwarding->a), (b.__forwarding->b));

    return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
