/*
 -------------------------------------
 File:    mymortgage.c
 Project: faro6867_a01
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-17
 -------------------------------------
 */
#include <math.h>
#include "mymortgage.h"

float monthly_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthlyLoan = years * 12;
	float monthlyInterest = annual_interest_rate / 100 / 12;
	float numerator = principal_amount * monthlyInterest
			* pow(1 + monthlyInterest, monthlyLoan);
	float denominator = pow(1 + monthlyInterest, monthlyLoan) - 1;
	float monthlyPayment = numerator / denominator;
	return monthlyPayment;
}

float total_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthlyPayment = monthly_payment(principal_amount,
			annual_interest_rate, years);
	float totalPayment = monthlyPayment * years * 12;
	return totalPayment;
}

float total_interest(float principal_amount, float annual_interest_rate,
		int years) {
	float totalPayment = total_payment(principal_amount, annual_interest_rate,
			years);
	float total_interest = totalPayment - principal_amount;

	return total_interest;
}
