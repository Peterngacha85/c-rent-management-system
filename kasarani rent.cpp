//Kasarani rent programme.
#include<iostream>
#include <iomanip>
#include<windows.h>
#include<unistd.h>
using namespace std;
int yesNo;
string Hnumber[7] = {"BO","1A","1B","2A","2B","3A","3B"}, modeOfPayment[7];
string houses[7] = {};
int garbage = 250, singleTotal = 0, token = 100, waterUnits = 0, clientWaterBillTotal, totalgarbage , totaltoken, allsingleTotal;
float totalWaterBill = 1.0, unitPrice = 90.0, water = 0;
int totalHouses = 8, previousmeter, currentmeter, date,  month,  year;
int dates[7],  months[7], modeOfPayments;
string newMonth;
class Kasarani{
 public: void display(){

 	cout<<"-----------------------------------------------------------------------------------------\n\n";
 	cout<<"                                        "<<newMonth<<"\n\n";
 	cout<<"\t\tHOUSE NUMBER\tRENT RECEIPT\tWATER\tGARBAGE\tTOKEN\tTOTAL\n";
 	cout<<"\t\t"<<Hnumber[0]<<"\t\t"<<houses[0] <<"\t\t"<<setprecision(3)<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[1]<<"\t\t"<<houses[1] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[2]<<"\t\t"<<houses[2] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[3]<<"\t\t"<<houses[3] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[4]<<"\t\t"<<houses[4] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[5]<<"\t\t"<<houses[5] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl;
 	cout<<"\t\t"<<Hnumber[6]<<"\t\t"<<houses[6] <<"\t\t"<<water <<"\t"<<garbage<<"\t"<<token<<"\t"<< singleTotal<<endl<<"\n";
 	cout<<"\t\tTOTAL \t\t\t\t"<<clientWaterBillTotal<<"\t"<<totalgarbage<<"\t"<<totaltoken<<"\t"<<allsingleTotal;
 	cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
 	cout<<"\t\tMain meter start : "<<previousmeter<<". Main meter stop. : "<<currentmeter<<endl;
 	cout<<"\t\tUnits consumed : "<<waterUnits<<" Units\n";
 	cout<<"\t\tTotal amount : "<<setprecision(3)<< totalWaterBill<<" ksh.\n";
 	cout<<"\t\tAmount per house : "<<water<<"\n";
 	cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
 	cout<<"\t\t\tHOUSE RENT DATE OF PAYMENT\n\n";
 	system("color 27");
 	cout<<"\t\t1. BO  "<<dates[0]<<"/"<<months[0]<<"/"<< year<<"\t"<<modeOfPayment[0]<<endl;
 	cout<<"\t\t2. 1A  "<<dates[1]<<"/"<<months[1]<<"/"<< year<<"\t"<<modeOfPayment[1]<<endl;
 	cout<<"\t\t3. 1B  "<<dates[2]<<"/"<<months[2]<<"/"<< year<<"\t"<<modeOfPayment[2]<<endl;
 	cout<<"\t\t4. 2A  "<<dates[3]<<"/"<<months[3]<<"/"<< year<<"\t"<<modeOfPayment[3]<<endl;
 	cout<<"\t\t5. 2B  "<<dates[4]<<"/"<<months[4]<<"/"<< year<<"\t"<<modeOfPayment[4]<<endl;
 	cout<<"\t\t6. 3A  "<<dates[5]<<"/"<<months[5]<<"/"<< year<<"\t"<<modeOfPayment[5]<<endl;
 	cout<<"\t\t7. 3B  "<<dates[6]<<"/"<<months[6]<<"/"<< year<<"\t"<<modeOfPayment[6]<<endl;
 	cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
 	
	
 };
 public: void paidNotpaid(){
 		system("color 57");
 			cout<<"Set the month of the year:\n";
        	cin>>newMonth;
	        system("cls");
 	for(int i=0; i<7; i++){

 	cout<<"Has "<<Hnumber[i] <<" paid the rent\n1. Paid\n2.Unpaid\n";
 	cin>>yesNo;
 	switch(yesNo){
 		case 1:
 			cout<<"Paid\n";
 			houses[i] = "Paid";
 			break;
 		case 2:
 			houses[i] = "Unpaid";
 			break;
 		default:
 			paidNotpaid();
 			
	 }
  	
system("cls");

 }
 meterReading();
}
 public:void meterReading(){

 singleTotal = water + garbage + token;
 cout<<"Enter the previous meter reading\n";
 cin>>previousmeter;
 cout<<"Enter the current meter reading\n";
 cin>>currentmeter;
 if(currentmeter < previousmeter){
 	system("cls");
 	cout<<"Current meter reading must be greater or equal to \nprevious meter reading\n\n";
	Beep(1000,200);
	system("color 47");
	sleep(5);
	
	system("cls");
	meterReading();
 }else{
 	 calculations();
 };
 calculations();
 };
//calculations.
public: void calculations(){

 system("cls");
 system("color 57");
 waterUnits = currentmeter - previousmeter;
 water = waterUnits * unitPrice / totalHouses ;
 totalWaterBill = waterUnits * totalWaterBill * unitPrice;
 clientWaterBillTotal = water * totalHouses - water;
 singleTotal = water + garbage + token;
 totalgarbage = garbage * totalHouses - 250;
 totaltoken = token * totalHouses - 100;
 allsingleTotal = singleTotal * totalHouses;
 
 cout<<"Set the following dates when the rent was paid:\nFomart is DD/MM/YYYY\n";
 for(int j=0; j<7; j++){
 	cout<<Hnumber[j]<<" date of payment: \n";
 	cin>>date;
 	dates[j] = date;
 	cout<<Hnumber[j]<<" month of payment: \n";
 	cin>>month;
 	months[j] = month;
 	system("cls");
 }
 
 cout<<"Set year: \n";
 cin>>year;
 year = year;
 	system("cls");
 	mode_of_payment();
};
 //mode of payment.
 public: void mode_of_payment(){

 cout<<"The mode of payment is either Bank or Receipt:\n";
 for(int k=0; k<7; k++){
 	cout<<Hnumber[k]<<" mode of payment: \n1.BANK\n2.RECEIPT\n";
 	cin>>modeOfPayments;
 	switch(modeOfPayments){
 		case 1:
 			modeOfPayment[k] ="Bank";
 			break;
 		case 2:
 			modeOfPayment[k] ="Receipt";
 			break;
 		default:
 		mode_of_payment();
	 }

 	
 	system("cls");
 	
 };
 display();
 sleep(1000);
 };

};


int main (){
	Kasarani K;
	K.paidNotpaid();
	return 0;
}
