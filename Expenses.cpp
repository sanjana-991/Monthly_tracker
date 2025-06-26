#include<iostream>
#include<fstream>
using namespace std;

const int Month = 12;
class ExpenseTracker{
	private:
		pair<string,int> expense[Month];
		string monthnames[Month] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		
	public:
		void inputExpenses(){
			cout << "Enter your monthly expenses (Jan-Dec):" << endl;
			for(int i=0;i<Month;i++){
				int value;
				cout << "Expense for\t" << monthnames[i] << "\n:";
				cin >> value;
				if(value < 0){
					cout << "Wrong enter!!\nExpenses cannot be negative" << endl;
					return ;
				}
				expense[i] = make_pair(monthnames[i], value);
			}
		}
		
		void showExpenses(){
			int sum=0, maxVal=expense[0].second, minVal=expense[0].second;
			string maxMonth=expense[0].first, minMonth=expense[0].first;
			cout << "=====================SUMMARY====================="<< endl;
			cout << "The monthly expenses for this year are: " << endl;
			for(int i=0;i<Month;i++){
				cout << expense[i].first <<"\t:" << expense[i].second << endl;
				sum += expense[i].second;
				if(expense[i].second > maxVal){
					maxVal = expense[i].second;
					maxMonth = expense[i].first;
				}
				if(expense[i].second < minVal){
					minVal = expense[i].second;
					minMonth = expense[i].first;
				}
			}
		cout << "*****************************" << endl;	
		cout << "\nTotal Expense of the year: " << sum;
        cout << "\nAverage Monthly Expense: ?" << sum / Month;
        cout << "\nMax Expense: " << maxVal << " in " << maxMonth;
        cout << "\nMin Expense: " << minVal << " in " << minMonth;
		}
        
    	void exportToCSV(){
        	ofstream file("Monthly_expenses.csv");
        	file << "Month,Expense\n";
        	for (int i = 0; i < Month; i++) {
            	file << expense[i].first << "," << expense[i].second << "\n";
        	}
        file.close();
        cout << "\n Data exported to 'Monthly_expenses.csv'\n";
   		}

};
int main()
{
	ExpenseTracker et;
	et.inputExpenses();
	et.showExpenses();
	et.exportToCSV();
	return 0;
}


