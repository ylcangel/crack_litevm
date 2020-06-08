struct lvm_runtime { // 最多支持62个, 63个
	size_t inited; // 初始化后为0xB8A3
	size_t thread_id; // 当前线程id
	// 可以理解为pc, 当前指令的位置，当前vcode对应的handler的起始位置
	void* vcode_pc; // 马上准备调用的函数; 刚刚进入函数时，它保存的上一次调用的函数地址
	struct lvm_stack* caller_stack; // 调用者栈，从上次执行的curr_stack拷贝得来
	void* stack_top; // ((char*)new_stack + stack_size) & 0xFFFFFFF8, 对齐8
	void* stack_base; // 1m的大小，指向其起始地址
	size_t stack_size; // 栈大小，默认0x100000=1m字节，它先从context->default_stack_size中获取大小
	void* v8;
	// 作为进入vmethod的当前栈使用
	struct lvm_stack curr_stack; // 创建新lvm_runtime时创建这个栈
	void* vm_runtime_end;
};