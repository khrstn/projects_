#include <iostream>
using namespace std;

void Sw(int task, int year2, int day2, int month2, int year1, int month1, int day1){
    cout << "Enter 1 date - ";
    cin >> day1 >> month1 >> year1;
    
    cout << "Enter 2 date - ";
    cin >> day2 >> month2 >> year2;
    
    if (day1 < 1 || day1 > 31 || day2 < 1 || day2 > 31 || month1 < 1 || month1 > 12 || month2 < 1 || month2 > 12 || year1 < 1900 || year2 < 1900){
        cout << "Wrong date entered!" << endl;
    } else {
        switch (task) {
            case 1:{
                int d = 0, feb = 0;
                if (year2 % 4 == 0){
                    if (year2 % 100 != 0 || (year2 % 100 == 0 && year2 % 400 == 0)){
                        d = 366;
                        feb = 29;
                    }
                } else {
                    d = 365;
                    feb = 28;
                }
                
                int temp = day2;
                if (year1 != year2){
                    for (int m = 1; m < month2; m++){
                        if (m <= 7){
                            if (m % 2 == 0){
                                if (m == 2){
                                    temp += feb;
                                } else {
                                    temp += 30;
                                }
                            } else {
                                temp += 31;
                            }
                        } else {
                            if (m % 2 == 0){
                                temp += 31;
                            } else {
                                temp += 30;
                            }
                        }
                        // days2 = к-ть днів від січня до дати2
                    }
                } else {
                    for (int m = month1; m < month2; m++){
                        if (m <= 7){
                            if (m % 2 == 0){
                                if (m == 2){
                                    temp += feb;
                                } else {
                                    temp += 30;
                                }
                            } else {
                                temp += 31;
                            }
                        } else {
                            if (m % 2 == 0){
                                temp += 31;
                            } else {
                                temp += 30;
                            }
                        }
                        // day2 = к-ть днів від січня до дати2
                    }
                    cout << temp - day1 << " days passed between the two dates." << endl;
                }
                
                int d1 = 0, feb1 = 0;
                if (year1 % 4 == 0){
                    if (year1 % 100 != 0 || (year1 % 100 == 0 && year1 % 400 == 0)){
                        d1 = 366;
                        feb1 = 29;
                    }
                } else {
                    d1 = 365;
                    feb1 = 28;
                }
                
                int temp1 = 0;
                for (int m = month1; m < 13; m++){
                    if (m <= 7){
                        if (m % 2 == 0){
                            if (m == 2){
                                temp1 += feb;
                            } else {
                                temp1 += 30;
                            }
                        } else {
                            temp1 += 31;
                        }
                    } else {
                        if (m % 2 == 0){
                            temp1 += 31;
                        } else {
                            temp1 += 30;
                        }
                    }
                }
                int days1 = temp1 - day1; // к-ть днів від дати 1 до січня
                
                int year_d = 0, year_days = 0;
                for (int year = year1 + 1; year < year2; year++){
                    if (year % 4 == 0){
                        if (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)){
                            year_d = 366;
                        }
                    } else {
                        year_d = 365;
                    }
                    year_days += year_d;
                }
                
                if (year1 != year2){
                    int res = 0;
                    res = days1 + temp + year_days;
                    cout << res << " days passed between the two dates." << endl;
                }
                break;
            }
                
            case 2:{
                for (int year = year1; year <= year2; year++){
                    int a, b, c, d;
                    a = (14 - 1) / 12;
                    b = year - a;
                    c = 1 + 12 * a - 2;
                    d = 1 + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                    int i = d - 7;
                    while (i >= 7) {
                        i = i - 7;
                    }
                    cout << year << " - ";
                    switch(i){
                        case 0:
                            cout << "Sunday" << endl;
                            break;
                        case 1:
                            cout << "Monday" << endl;
                            break;
                        case 2:
                            cout << "Tuesday" << endl;
                            break;
                        case 3:
                            cout << "Wednesday" << endl;
                            break;
                        case 4:
                            cout << "Thursday" << endl;
                            break;
                        case 5:
                            cout << "Friday" << endl;
                            break;
                        case 6:
                            cout << "Saturday" << endl;
                            break;
                    }
                }
                break;
            }
                
            case 3:{
                int friday = 0;
                
                for (int month = 1; month <= 12; month++){
                    int day = 1;
                    int a, b, c, d;
                    a = (14 - month) / 12;
                    b = year2 - a;
                    c = month + 12 * a - 2;
                    d = day + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                    int i = d - 7;
                    while (i >= 7)
                    {
                        i = i - 7;
                    }
                    if (i == 0){
                        friday ++;
                    }
                }
                cout << "In " << year2 << " year " << friday << " friday(-s) 13th" << endl;
                break;
            }
                
            case 4:{
                int a, b, c, d;
                a = (14 - month1) / 12;
                b = year1 - a;
                c = month1 + 12 * a - 2;
                d = day1 + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                int i = d - 7;
                while (i >= 7) {
                    i = i - 7;
                }
                cout << day1 << "." << month1 << "." << year1 << " - ";
                switch(i){
                    case 0:
                        cout << "Sunday" << endl;
                        break;
                    case 1:
                        cout << "Monday" << endl;
                        break;
                    case 2:
                        cout << "Tuesday" << endl;
                        break;
                    case 3:
                        cout << "Wednesday" << endl;
                        break;
                    case 4:
                        cout << "Thursday" << endl;
                        break;
                    case 5:
                        cout << "Friday" << endl;
                        break;
                    case 6:
                        cout << "Saturday" << endl;
                        break;
                }
                break;
            }
                
            case 5:{
                cout << "Enter k - ";
                int k = 0;
                cin >> k;
                
                int y2 = year2;
                int m2 = month2;
                int d2 = day2;
                
                for (int numb = 1; numb <=k; numb++){
                    if (d2 == 1){
                        m2 -= 1;
                        if (m2 == 0){
                            y2 -= 1;
                            m2 += 12;
                            if (m2 <= 7){
                                if (m2 % 2 != 0){
                                    d2 += 31;
                                } else if (m2 % 2 == 0 && (m2 != 0 || m2 != 2)){
                                    d2 += 30;
                                } else if (m2 == 2){
                                    if (y2 % 4 == 0){
                                        if (y2 % 100 != 0 || (y2 % 100 == 0 && y2 % 400 == 0)){
                                            d2 += 29;
                                        }
                                    } else {
                                        d2 += 28;
                                    }
                                }
                            } else {
                                if (m2 % 2 == 0){
                                    d2 += 31;
                                } else {
                                    d2 += 30;
                                }
                            }
                        } else if (m2 <= 7){
                            if (m2 % 2 != 0){
                                d2 += 31;
                            } else if (m2 == 2){
                                if (y2 % 4 == 0){
                                    if (y2 % 100 != 0 || (y2 % 100 == 0 && y2 % 400 == 0)){
                                        d2 += 29;
                                    }
                                } else {
                                    d2 += 28;
                                }
                            } else if (m2 % 2 == 0 && (m2 != 0 || m2 != 2)){
                                d2 += 30;
                            }
                        } else {
                            if (m2 % 2 == 0){
                                d2 += 31;
                            } else {
                                d2 += 30;
                            }
                        }
                    }
                    d2 -= 1;
                }
                cout << "k" << " - " << k << " -> ";
                
                int a, b, c, d;
                a = (14 - m2) / 12;
                b = y2 - a;
                c = m2 + 12 * a - 2;
                d = d2 + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                int i = d - 7;
                while (i >= 7) {
                    i = i - 7;
                }
                cout << d2 << "." << m2 << "." << y2 << " - ";
                switch(i){
                    case 0:
                        cout << "Sunday" << endl;
                        break;
                    case 1:
                        cout << "Monday" << endl;
                        break;
                    case 2:
                        cout << "Tuesday" << endl;
                        break;
                    case 3:
                        cout << "Wednesday" << endl;
                        break;
                    case 4:
                        cout << "Thursday" << endl;
                        break;
                    case 5:
                        cout << "Friday" << endl;
                        break;
                    case 6:
                        cout << "Saturday" << endl;
                        break;
                }
                break;
            }
                
            case 6:{
                int d2 = day2;
                int m2 = month2;
                int y2 = year2;
                bool res = true;
                
                if (d2 > 13){
                    m2++;
                }
                int i = 0;
                for (int m = m2; m < 13; m++){
                    int day = 1;
                    int a, b, c, d;
                    a = (14 - m) / 12;
                    b = y2 - a;
                    c = m + 12 * a - 2;
                    d = day + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                    i = d - 7;
                    while (i >= 7){
                        i -= 7;
                    }
                    if (i == 0){
                        res = false;
                        cout << "13" << "." << m << "." << y2 << endl;
                        break;
                    }
                }
                
                if (res == true){
                    y2 += 1;
                    for (int m = 1; m < 13; m++){
                        int day = 1;
                        int a, b, c, d;
                        a = (14 - m) / 12;
                        b = y2 - a;
                        c = m + 12 * a - 2;
                        d = day + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12;
                        i = d - 7;
                        while (i >= 7){
                            i -= 7;
                        }
                        if (i == 0){
                            res = false;
                            cout << "13" << "." << m << "." << y2 << endl;
                            break;
                        }
                    }
                }
                break;
            }
                
            case 0:{
                cout << "Program is over! Goodbye! ^-^" << endl;
                break;
            }
                
            default:{
                cout << "Wrong task! Try again! ^-^" << endl;
                break;
            }
        }
        if (task != 0){
            cout << endl;
            cout << "1 - how many days passed between the dates?" << endl;
            cout << "2 - on which days of the week does the New Year fall in the years between the given ones?" << endl;
            cout << "3 - how many Friday the 13th in year 2?" << endl;
            cout << "4 - on which day of the week were you born? (date 1)" << endl;
            cout << "5 - what day of the week was date 2 - k?" << endl;
            cout << "6 - the first Friday the 13th after the set date 2." << endl;
            cout << "0 - exit the program." << endl;
            cout << endl;
            cout << "Which task to do? ";
            cin >> task;
            cout << endl;
            Sw(task, year2, day2, month2, year1, month1, day1 );
        }
    }
}

int main(){
    
    cout << "***** WELCOME TO PROGRAMME *****" << endl;
    cout << "1 - how many days passed between the dates?" << endl;
    cout << "2 - on which days of the week does the New Year fall in the years between the given ones?" << endl;
    cout << "3 - how many Friday the 13th in year 2?" << endl;
    cout << "4 - on which day of the week were you born? (date 1)" << endl;
    cout << "5 - what day of the week was date 2 - k?" << endl;
    cout << "6 - the first Friday the 13th after the set date 2." << endl;
    cout << "0 - exit the program." << endl;
    cout << endl;
    
    int task = 0;
    cout << "Which task to do? ";
    cin >> task;
    cout << endl;
    
    int year2, day2, month2, year1, month1, day1;
    
    Sw(task, year2, day2, month2, year1, month1, day1);
    
    return 0;
}
