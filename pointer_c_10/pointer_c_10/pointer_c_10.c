#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef union
{
	unsigned short addr;
	struct {
		unsigned opcode : 10;
		unsigned dst_mode : 3;
		unsigned dst_reg : 3;
	} sgl_op;
	struct {
		unsigned opcode : 4;
		unsigned src_mode : 3;
		unsigned src_reg : 3;
		unsigned dst_mode : 3;
		unsigned dst_reg : 3;
	} dbl_op;
	struct {
		unsigned opcode : 7;
		unsigned src_reg : 3;
		unsigned dst_mode : 3;
		unsigned dst_reg : 3;
	} reg_src;
	struct {
		unsigned opcode : 8;
		unsigned offset : 8;
	} branch;
	struct {
		unsigned opcode : 16;
	} misc;
} machine_inst;
struct info
{
	char cust_name[21];
	char cust_addr[41];
	char model[21];
	enum {
		pure_cash,
		cash_loan,
		lease
	}type;
};
union
{
	struct {
		float msrp;
		float asp;
		float sales_tax;
		float licensing_fee;
	} pure_cash;
	struct {
		float msrp;
		float sales_price;
		float sales_tax;
		float licensing_fee;
		float down_payment;
		int loan_duration;
		float interest_rate;
		float monthly_payment;
		char bank[21];
	} cash_loan;
	struct {
		float msrp;
		float sales_price;
		float down_payment;
		float security_deposit;
		float monthly_payment;
		float lease_term;
	} lease;
};
struct phone
{
	int area;
	int exchange;
	int station;
};
struct long_call
{
	int year;
	int month;
	int day;
	struct phone called;
	struct phone calling;
	struct phone billed;
};
struct a
{
	signed int b : 2;
};
int main()
{
	struct a name = { 1 };
	name.b += 1;
	printf("%d", name.b);
	return 0;
}