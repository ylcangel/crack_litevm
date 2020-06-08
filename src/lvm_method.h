// 部分在数据段如off_CD460，完整的在内存中，用完会被释放
// 最多接受15个参数
// 所有方法的集合，包括系统的、自实现的、lvm的方法
// 这些方法中有不同的但完成相同功能的，如do_llc_syscall和大多数系统调用方法
// 也是某些vcode的handler
struct lvm_method { // 沙盒方法的抽象，多种类的，外部通过一个入口调用这些函数
	char* method_name; // 对应JNI method或其他方法名
	void* func; // 函数地址
	int mtype; // 暂时不知道这些数字代表啥， 0, 1， 2，3， 4，7 ，可以大于16
	int is_has_retv; // 是否存在返回值，1有0没有，仅适用于litevm 和 jni
	int is_litevm_method; // 0不是，1是， 它转接的jni方法此标记也为1
};