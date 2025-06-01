#include <stdio.h>
#include <string.h> //only two function imported i.e. strlen and memset(for intialization of a big string)

typedef enum{FALSE,TRUE} bool;

bool sign_check(char * a){
	char temp;
	temp=a[0];
	if(temp!='\0'){
		if(temp>='0' && temp<='9'){
			return FALSE;
		}
		else{
			if(temp=='+'){
				return FALSE;
			}
			else{ //if temp == '-'
				return TRUE;
			}
		}
	}
	return FALSE;// suggesting it might be a=0
}

bool sign_a_minus_b(char *a,char *b){      //return if 0 if a>=b else 1
	bool retval;
	if(strlen(a)>strlen(b)){
		retval=FALSE;
	}
	else if (strlen(a)<strlen(b)){
		retval=TRUE;
	}
	else{
		int i;
		i=0;
		while(a[i]!='\0' && a[i]==b[i]){
			i++;
		}
		if(a[i]<b[i]){
			retval=TRUE;
		}
		else{
			retval=FALSE;
		}
	}
	return retval;
} 


void correctnewline(char *s){
	int i;
	i=0;
	while(s[i]!='\n' && s[i]!='\0'){
		i++;
	}
	s[i]='\0';
}


void rev_num_str(char *s,int size){
	int i=0;
	char temp;
	for(i=0;i<size/2;i++){
		temp=s[i];
		s[i]=s[size-i-1];
		s[size-i-1]=temp;
	}
	s[size]='\0';
}

void add_2_num(char *s1,char *s2,char *s3){
	int i,k,temp_num;
	bool carry=FALSE;
	i=k=0;
	while(s1[i]!='\0' && s2[i]!='\0'){
		temp_num=s1[i]+s2[i]-'0'*2+carry;
		
		s3[k++]=(temp_num%10)+'0';		//same as temp_num%10+'0'
//		print(s3[k-1]);
		carry=temp_num/10;
		++i;
	}
	if(s1[i]=='\0'){
		for(;s2[i]!='\0';i++){
			temp_num=s2[i]-'0'+carry;
			s3[k++]=(temp_num%10)+'0';		//same as temp_num%10+'0'
//			print(s3[k-1]);
			carry=temp_num/10;
		}
	}
	else{
		for(;s1[i]!='\0';i++){
				temp_num=s1[i]-'0'+carry;
				s3[k++]=(temp_num%10)+'0';		//same as temp_num%10+'0'
//				print(s3[k-1]);
				carry=temp_num/10;
		}
	}
	if(carry>0){
		s3[k++]=carry+'0';
	}
	s3[k]='\0';
}

void sub_2_num(char *s1,char *s2,char *s3,int sizemax){
	int i,k,temp_num;
	bool borrow=FALSE;
	i=k=0;
	while(s1[i]!='\0' && s2[i]!='\0'){
		temp_num=s1[i]-s2[i]-borrow;
		borrow=(temp_num<0)?temp_num+=10,TRUE:FALSE;
		s3[k++]=temp_num+'0';		//same as temp_num%10+'0'
		++i;
	}
	if(s1[i]=='\0'){
		for(;i<sizemax;i++){
			temp_num=s2[i]-'0'-borrow;
			if(temp_num<0){
				borrow=TRUE;
				temp_num+=10;
			}
			else{
				borrow=FALSE;
			}
			s3[k++]=temp_num+'0';		//same as temp_num%10+'0'
		}
	}
	else{
		for(;i<sizemax;i++){
				temp_num=s1[i]-'0'-borrow;
				if(temp_num<0){
					borrow=TRUE;
					temp_num+=10;
				}
				else{
					borrow=FALSE;
				}
				s3[k++]=temp_num+'0';		//same as temp_num%10+'0'
		}
	}
	s3[k]='\0';
}

int mul_a_b(char a,char b,int *carryptr){
	int temp;
	temp=(a-'0')*(b-'0')+ *(carryptr);
	*carryptr=temp/10;
	return temp%10;
}

void mul_2_num(char *s1,char *s2,char *temp){
	int i,k,j,carry,sum_carry;
	k=0;
	for(i=0;s1[i]!='\0';i++){
		sum_carry=0;
		carry=0;
		k=0;
		for(j=0;s2[j]!='\0';j++){
			temp[k+i]+=mul_a_b(s1[i],s2[j],&carry)+sum_carry;
			if(temp[k+i]>'9'){
				temp[k+i]-=10;
				sum_carry=1;
			}
			else{
				sum_carry=0;
			}
			k++;
		}
		if((carry+sum_carry)!=0){
			temp[k+i]+=carry+sum_carry;k++;
		}
	
	}
	temp[k+i-1]='\0';	//printf("\t%s\n",temp);
	if(k+i-1<=0){
		temp[0]='0';
		temp[1]='\0';
	}
}


void decorator(int a){
	int i=0;
	for(i=0;i<a;i++){
		printf("*");
	}
}

void print_menu(){
	printf("\n\n\tThis is a 1024 bit addition,subtractor and division calculator \n");
	printf("\tThis Calculator accepts number in decimal (with sign if negative) \n\tof maximum length 309 which is 1024 bit in binary\n");
	printf("\tChoose the appropriate option(number)\n");
	printf("\t1. Subtraction\n\t2. Addition\n\t3. Multiplication\n");
	printf("\tPress any other key to Exit\n\n\tEnter choice Number:");
}


int main(){
	decorator(80);
	int option,i;
	bool sign1,sign2,sign3,sign_a_b,result_sign;//1 for negative
	char s1[309],s2[309],s3[100000];
	print_menu();
	scanf("%d",&option);
	while(option>0 && option<4){
		memset(s3,'0',sizeof(s3));
		getchar();
		sign1=sign2=sign3=0;
		printf("\n\tEnter first number  : ");
		fgets(s1,sizeof(s1),stdin);
		sign1=sign_check(s1);
		printf("\tEnter second number : ");
		fgets(s2,sizeof(s2),stdin);
		sign2=sign_check(s2);
		correctnewline(s1);
		correctnewline(s2);
		sign_a_b=sign_a_minus_b(&s1[sign1],&s2[sign2]);
		rev_num_str(s1,strlen(s1));
		if(sign1){
			s1[strlen(s1)-1]='\0';
		}
		rev_num_str(s2,strlen(s2));
		if(sign2){
			s2[strlen(s2)-1]='\0';
		}
		i=(strlen(s1)>strlen(s2))?strlen(s1):strlen(s2);
		if(option==3){
			mul_2_num(s1,s2,s3);
			rev_num_str(s3,strlen(s3));
			printf("\tAns:\t");
			if(sign1+sign2==1){		// to print negative number 
				printf("-");
			}
			printf("%s\n\n",s3);
		}
		else{ 		//addition and subtraction 

			if((option+sign1+sign2)%2==1){		//sub=1 ; if sum of all negative then we have to do subtraction of abs
				
				if(sign_a_b==0){ // denoting a>=b
					sub_2_num(s1,s2,s3,i);
				}
				else{
					sub_2_num(s2,s1,s3,i);
				}
			}
			else{ 			//we have to add else the abs value 
				add_2_num(s1,s2,s3);
			}
			printf("\tAns:\t");
			if(sign_a_b==0){
				result_sign=sign1;
			}
			else{
				result_sign=(sign2+option)%2;		//gives the sign of b with operation add or sub
			}
			if(result_sign==TRUE){		//denotes number is negative
				printf("-");
			}
			rev_num_str(s3,strlen(s3));
			printf("%s\n\n",s3);
		}
		decorator(80);
		printf("\n");
		print_menu();
		scanf("%d",&option);
		memset(s1,'0',sizeof(s1));
		memset(s2,'0',sizeof(s2));
		
	}
	printf("\n\n");
	decorator(35);
	printf(" Thank You ");
	decorator(35);
	printf("\n");
	return 0;
}
