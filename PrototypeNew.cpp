#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include <windows.h>
#include "Combined.h"
#include "Database.h"
#include <random>
#include <cstdlib>
#include <ctime>


using namespace std;

int samplenum;
double joymax = 0;
double fearmax = 0;
double disgustmax = 0;
double sadnessmax = 0;
double angermax = 0;
double surprisemax = 0;
double contemptmax = 0;
double timemax = 0;
double timestamps[35];
double maxvalues[34][7];
double empathValues[34][5];
double combinedvalues[34][11];
double sout;
double nsucsum = 0;
double nfaisum = 0;

double toCSV[5];

string predictions[34][4];
string nnResults;
string nbResults;
string svmResults;
string j48Results;
string dataInput;
string newInput;





class line {
public:
	
	string TimeStamp;
	string faceID;
	string interocularDistance;
	string glasses;
	string age;
	string ethnicity;
	string gender;
	string dominant;
	string pitch;
	string yaw;
	string roll;
	string joy;
	string fear;
	string disgust;
	string sadness;
	string anger;
	string surprise;
	string contempt;
	string valence;
	string engagement;
	string smile;
	string innerBrowRaise;
	string browRaise;
	string browFurrow;
	string noseWrinkle;
	string upperLipRaise;
	string lipCornerDepressor;
	string chinRaise;
	string lipPucker;
	string lipPress;
	string lipSuck;
	string mouthOpen;
	string smirk;
	string eyeClosure;
	string attention;
	string eyeWiden;
	string cheekRaise;
	string lidTighten;
	string dimpler;
	string lipStretch;
	string jawDrop;
	string relaxed;
	string smiley;
	string laughing;
	string kissing;
	string disappointed;
	string rage;
	string smirk1;
	string wink;
	string stuckOutTongueWinkingEye;
	string stuckOutTongue;
	string flushed;
	string scream;
	void setvalues(string i1, string i2, string i3, string i4, string i5, string i6, string i7, string i8, string i9, string i10, string i11, string i12, string i13, string i14, string i15, string i16, string i17, string i18, string i19, string i20, string i21, string i22, string i23, string i24, string i25, string i26, string i27, string i28, string i29, string i30, string i31, string i32, string i33, string i34, string i35, string i36, string i37, string i38, string i39, string i40, string i41, string i42, string i43, string i44, string i45, string i46, string i47, string i48, string i49, string i50, string i51, string i52, string i53);
};
void line::setvalues(string i1, string i2, string i3, string i4, string i5, string i6, string i7, string i8, string i9, string i10, string i11, string i12, string i13, string i14, string i15, string i16, string i17, string i18, string i19, string i20, string i21, string i22, string i23, string i24, string i25, string i26, string i27, string i28, string i29, string i30, string i31, string i32, string i33, string i34, string i35, string i36, string i37, string i38, string i39, string i40, string i41, string i42, string i43, string i44, string i45, string i46, string i47, string i48, string i49, string i50, string i51, string i52, string i53)
{
	TimeStamp = i1;
	faceID = i2;
	interocularDistance = i3;
	glasses = i4;
	age = i5;
	ethnicity = i6;
	gender = i7;
	dominant = i8;
	pitch = i9;
	yaw = i10;
	roll = i11;
	joy = i12;
	fear = i13;
	disgust = i14;
	sadness = i15;
	anger = i16;
	surprise = i17;
	contempt = i18;
	valence = i19;
	engagement = i20;
	smile = i21;
	innerBrowRaise = i22;
	browRaise = i23;
	browFurrow = i24;
	noseWrinkle = i25;
	upperLipRaise = i26;
	lipCornerDepressor = i27;
	chinRaise = i28;
	lipPucker = i29;
	lipPress = i30;
	lipSuck = i31;
	mouthOpen = i32;
	smirk = i33;
	eyeClosure = i34;
	attention = i35;
	eyeWiden = i36;
	cheekRaise = i37;
	lidTighten = i38;
	dimpler = i39;
	lipStretch = i40;
	jawDrop = i41;
	relaxed = i42;
	smiley = i43;
	laughing = i44;
	kissing = i45;
	disappointed = i46;
	rage = i47;
	smirk1 = i48;
	wink = i49;
	stuckOutTongueWinkingEye = i50;
	stuckOutTongue = i51;
	flushed = i52;
	scream = i53;
}
void reveal(line l)
{
	double djoy, dfear, ddisgust, dsadness, danger, dsurprise, dcontempt, dtime;
	try {
		djoy = stod(l.joy);
		dfear = stod(l.fear);
		ddisgust = stod(l.disgust);
		dsadness = stod(l.sadness);
		danger = stod(l.anger);
		dsurprise = stod(l.surprise);
		dcontempt = stod(l.contempt);
		dtime = stod(l.TimeStamp);
	}
	catch (exception e)
	{
		djoy = 0;
		dfear = 0;
		ddisgust = 0;
		dsadness = 0;
		danger = 0;
		dsurprise = 0;
		dcontempt = 0;
		dtime = 0;
	}
	if (djoy>joymax)
		joymax = djoy;

	if (dfear>fearmax)
		fearmax = dfear;

	if (ddisgust>disgustmax)
		disgustmax = ddisgust;

	if (dsadness>sadnessmax)
		sadnessmax = dsadness;

	if (danger>angermax)
		angermax = danger;

	if (dsurprise>surprisemax)
		surprisemax = dsurprise;

	if (dcontempt>contemptmax)
		contemptmax = dcontempt;
	if (dtime > timemax)
		timemax = dtime;
}
vector<line> vic;
vector<line> vic1;
vector<line> vic2;
vector<line> vic3;
vector<line> vic4;
vector<line> vic5;
vector<line> vic6;
vector<line> vic7;
vector<line> vic8;
vector<line> vic9;
vector<line> vic10;
vector<line> vic11;
vector<line> vic12;
vector<line> vic13;
vector<line> vic14;
vector<line> vic15;
vector<line> vic16;
vector<line> vic17;
vector<line> vic18;
vector<line> vic19;
vector<line> vic20;
vector<line> vic21;
vector<line> vic22;
vector<line> vic23;
vector<line> vic24;
vector<line> vic25;
vector<line> vic26;
vector<line> vic27;
vector<line> vic28;
vector<line> vic29;
vector<line> vic30;
vector<line> vic31;
vector<line> vic32;
vector<line> vic33;
vector<line> vic34;
database d;
void split(line l)
{
	double time;
	try {
		time = stod(l.TimeStamp);
	}
	catch (exception e)
	{
		time = 0;
	}

	if (time >= timestamps[0])
	{
		if (time < timestamps[1])
			vic1.push_back(l);
	}
	if (time >= timestamps[1])
	{
		if (time < timestamps[2])
			vic2.push_back(l);
	}
	if (time >= timestamps[2])
	{
		if (time < timestamps[3])
			vic3.push_back(l);
	}
	if (time >= timestamps[3])
	{
		if (time < timestamps[4])
			vic4.push_back(l);
	}
	if (time >= timestamps[4])
	{
		if (time < timestamps[5])
			vic5.push_back(l);
	}
	if (time >= timestamps[5])
	{
		if (time < timestamps[6])
			vic6.push_back(l);
	}
	if (time >= timestamps[6])
	{
		if (time < timestamps[7])
			vic7.push_back(l);
	}
	if (time >= timestamps[7])
	{
		if (time < timestamps[8])
			vic8.push_back(l);
	}
	if (time >= timestamps[8])
	{
		if (time < timestamps[9])
			vic9.push_back(l);
	}
	if (time >= timestamps[9])
	{
		if (time < timestamps[10])
			vic10.push_back(l);
	}
	if (time >= timestamps[10])
	{
		if (time < timestamps[11])
			vic11.push_back(l);
	}
	if (time >= timestamps[11])
	{
		if (time < timestamps[12])
			vic12.push_back(l);
	}
	if (time >= timestamps[12])
	{
		if (time < timestamps[13])
			vic13.push_back(l);
	}
	if (time >= timestamps[13])
	{
		if (time < timestamps[14])
			vic14.push_back(l);
	}
	if (time >= timestamps[14])
	{
		if (time < timestamps[15])
			vic15.push_back(l);
	}
	if (time >= timestamps[15])
	{
		if (time < timestamps[16])
			vic16.push_back(l);
	}
	if (time >= timestamps[16])
	{
		if (time < timestamps[17])
			vic17.push_back(l);
	}
	if (time >= timestamps[17])
	{
		if (time < timestamps[18])
			vic18.push_back(l);
	}
	if (time >= timestamps[18])
	{
		if (time < timestamps[19])
			vic19.push_back(l);
	}
	if (time >= timestamps[19])
	{
		if (time < timestamps[20])
			vic20.push_back(l);
	}
	if (time >= timestamps[20])
	{
		if (time < timestamps[21])
			vic21.push_back(l);
	}
	if (time >= timestamps[21])
	{
		if (time < timestamps[22])
			vic22.push_back(l);
	}
	if (time >= timestamps[22])
	{
		if (time < timestamps[23])
			vic23.push_back(l);
	}
	if (time >= timestamps[23])
	{
		if (time < timestamps[24])
			vic24.push_back(l);
	}
	if (time >= timestamps[24])
	{
		if (time < timestamps[25])
			vic25.push_back(l);
	}
	if (time >= timestamps[25])
	{
		if (time < timestamps[26])
			vic26.push_back(l);
	}
	if (time >= timestamps[26])
	{
		if (time < timestamps[27])
			vic27.push_back(l);
	}
	if (time >= timestamps[27])
	{
		if (time < timestamps[28])
			vic28.push_back(l);
	}
	if (time >= timestamps[28])
	{
		if (time < timestamps[29])
			vic29.push_back(l);
	}
	if (time >= timestamps[29])
	{
		if (time < timestamps[30])
			vic30.push_back(l);
	}
	if (time >= timestamps[30])
	{
		if (time < timestamps[31])
			vic31.push_back(l);
	}
	if (time >= timestamps[31])
	{
		if (time < timestamps[32])
			vic32.push_back(l);
	}
	if (time >= timestamps[32])
	{
		if (time < timestamps[33])
			vic33.push_back(l);
	}
	if (time >= timestamps[33])
	{
		if (time < timestamps[34])
			vic34.push_back(l);
	}
}

void displaymax(int i)
{
	std::cout << timemax << endl;
	maxvalues[i - 1][0] = joymax;
	maxvalues[i - 1][1] = fearmax;
	maxvalues[i - 1][2] = disgustmax;
	maxvalues[i - 1][3] = sadnessmax;
	maxvalues[i - 1][4] = angermax;
	maxvalues[i - 1][5] = surprisemax;
	maxvalues[i - 1][6] = contemptmax;
	joymax = 0;
	fearmax = 0;
	disgustmax = 0;
	sadnessmax = 0;
	angermax = 0;
	surprisemax = 0;
	contemptmax = 0;
	timemax = 0;
}
void convertDouble(string input, int query, int number)
{
	empathValues[query][number] = stod(input);
}
void empathstring(string emp, int query)
{

	emp.erase(emp.begin());
	string delimiter = ",";
	int i = 0;
	size_t pos = 0;
	size_t pos2 = 0;
	string token;
	while ((pos = emp.find(delimiter)) != std::string::npos) {
		token = emp.substr(0, pos);
		string delimiter2 = ":";
		pos2 = token.find(delimiter2);
		token.erase(0, pos2 + delimiter2.length());
		convertDouble(token, query, i);
		std::cout << token << endl;

		emp.erase(0, pos + delimiter.length());
		i++;
	}

}
void combine()
{
	for (int i = 0; i < 34; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j < 7)
				combinedvalues[i][j] = maxvalues[i][j];
			else
			{
				if (j == 7)
					combinedvalues[i][j] = empathValues[i][1];
				if (j == 8)
					combinedvalues[i][j] = empathValues[i][2];
				if (j == 9)
					combinedvalues[i][j] = empathValues[i][3];
				if (j == 10)
					combinedvalues[i][j] = empathValues[i][4];

			}
		}
	}
}

void modelPredictions(string output)
{
	ifstream outcsv;
	outcsv.open(output);
	try {
		for (int i = 0; outcsv.good(); i++)
		{
			getline(outcsv, predictions[i][0], ',');
			getline(outcsv, predictions[i][1], ',');
			getline(outcsv, predictions[i][2], ',');
			getline(outcsv, predictions[i][3], '\n');
		}
	}
	catch (exception e)
	{
		outcsv.close();
	}
}

void WekaJavaModel(string svmModel, string svmResult, string nbModel, string nbResult, string nnModel, string nnResult)
{

	string parameters = "-jar C:\\Users\\daniel-hp\\Downloads\\WekaJavaTest-master\\WekaJavaTest-master\\dist\\WekaJavaTest.jar " + svmModel + " " + svmResult + " " + nbModel + " " + nbResult + " " + nnModel + " " + nnResult;
	LPCSTR par = parameters.c_str();
	cout << "Reads Models from Weka" << endl;
	ShellExecuteA(NULL, "open", "C:\\Program Files\\Java\\jdk-9.0.4\\bin\\java.exe", par, NULL, SW_SHOWMAXIMIZED);
	system("PAUSE");


}
void j48ModelImplementation(string CSVnew, string ARFFnew, string J48model, string j48Result)
{
	string parameters = "-jar C:\\Users\\daniel-hp\\Downloads\\J48ModelApplication-master\\J48ModelApplication-master\\dist\\J48ModelApplication.jar " + CSVnew + " " + ARFFnew + " " + J48model + " " + j48Result;
	LPCSTR par = parameters.c_str();
	cout << "Reads J48 Model from Weka" << endl;
	ShellExecuteA(NULL, "open", "C:\\Program Files\\Java\\jdk-9.0.4\\bin\\java.exe", par, NULL, SW_SHOWMAXIMIZED);
	system("PAUSE");
}
void newCSV( string newer)
{
	cout << "Testing of New CSV creation" << endl;
	string contents[34][11];
	for (int i = 0; i < 34; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			contents[i][j] = to_string(combinedvalues[i][j]);
		}
	}

	ofstream newcsv;
	newcsv.open(newer);
	newcsv << "joy" << "," << "fear" << "," << "disgust" << "," << "sadness" << "," << "anger" << "," << "surprise" << "," << "contempt" << "," << "Calm" << "," << "Angered" << "," << "Joyful" << "," << "Sorrow" << "," << "Performance";
	newcsv << "\n";
	for (int i = 0; i < 34; i++)
	{
		newcsv << contents[i][0] << "," << contents[i][1] << "," << contents[i][2] << "," << contents[i][3] << "," << contents[i][4] << "," << contents[i][5] << "," << contents[i][6] << "," << contents[i][7] << "," << contents[i][8] << "," << contents[i][9] << "," << contents[i][10] << "," << "Low";
		newcsv << "\n";
	}
	newcsv << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << "High";
	newcsv << "\n";
	newcsv.close();
	cout << "Success!" << endl;
	/*

	cout << "Testing of New CSV creation" << endl;
	int i = 0;
	string contents[34][11];
	ifstream oldcsv;
	oldcsv.open(older);
	try
	{
		while (oldcsv.good())
		{
			if (i == 34)
			{
				break;
			}
			getline(oldcsv, contents[i][0], ',');
			getline(oldcsv, contents[i][1], ',');
			getline(oldcsv, contents[i][2], ',');
			getline(oldcsv, contents[i][3], ',');
			getline(oldcsv, contents[i][4], ',');
			getline(oldcsv, contents[i][5], ',');
			getline(oldcsv, contents[i][6], ',');
			getline(oldcsv, contents[i][7], ',');
			getline(oldcsv, contents[i][8], ',');
			getline(oldcsv, contents[i][9], ',');
			getline(oldcsv, contents[i][10], '\n');
			i++;
		}
	}
	catch (exception e)
	{
		oldcsv.close();
	}
	oldcsv.close();
	/*for (int m = 0; m < 34; m++)
	{
	for (int n = 0; n < 11; n++)
	{
	cout <<contents[m][n]<<" ";
	}
	cout << endl;
	}*/
	/*
	ofstream newcsv;
	newcsv.open(newer);
	newcsv << "joy" << "," << "fear" << "," << "disgust" << "," << "sadness" << "," << "anger" << "," << "surprise" << "," << "contempt" << "," << "Calm" << "," << "Angered" << "," << "Joyful" << "," << "Sorrow" << "," << "Performance";
	newcsv << "\n";
	for (int i = 0; i < 34; i++)
	{
		newcsv << contents[i][0] << "," << contents[i][1] << "," << contents[i][2] << "," << contents[i][3] << "," << contents[i][4] << "," << contents[i][5] << "," << contents[i][6] << "," << contents[i][7] << "," << contents[i][8] << "," << contents[i][9] << "," << contents[i][10] << "," << "Low";
		newcsv << "\n";
	}
	newcsv << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << "High";
	newcsv << "\n";
	newcsv.close();
	cout << "Success!" << endl;
	*/
}

void WekaModelApplication(string inputcsv, string inputarff, string j48model, string nnmodel, string svmmodel, string nbmodel, string output)
{
	cout << "Model Application" << endl;
	string parameter = "-jar C:\\Users\\LENOVO\\Desktop\\Thesis\\WekaModelImplementation-master\\dist\\WekaModelImplementation.jar " + inputcsv + " " + inputarff + " " + j48model + " " + nnmodel + " " + svmmodel + " " + nbmodel + " " + output;
	LPCSTR parameters = parameter.c_str();
	ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Java\\jre1.8.0_181\\bin\\java.exe", parameters, NULL, SW_SHOWMAXIMIZED);
	system("PAUSE");
}

void AffectivaProcess(string AffPath, string TimPath, string  AffCSVPath)
{
	std::cout << "Runs Affectiva" << endl;
	LPCSTR AffectivaPath = AffPath.c_str();

	

	//LPCSTR TimestampPath = TimPath.c_str();
	//insert Affectiva ShellExecute Here, and edit affpath for the csv. 

	//ShellExecuteA(NULL, "open", "C:\\Users\\daniel-hp\\Downloads\\cpp-sdk-samples-master\\cpp-sdk-samples-master\\affdex-win-samples.sln", "/p:Configuration=Release", NULL, SW_SHOWMAXIMIZED);

	//cout << "Opening solution";

	/* Temporary for Testing
	ShellExecuteA(NULL, "open", "C:\\Users\\daniel-hp\\Downloads\\cpp-sdk-samples-master\\cpp-sdk-samples-master\\x64\\Release\\video-demo.exe",  AffectivaPath , NULL, SW_SHOWMAXIMIZED);
	*/
// system("PAUSE");

//	ShellExecuteA(NULL, "open", "C:\\Users\\daniel-hp\\Downloads\\cpp-sdk-samples-master\\cpp-sdk-samples-master\\x64\\Release\\video-demo.exe", NULL, NULL, SW_SHOWMAXIMIZED);

	//std::cout << "Executing Video.exe";
	
	//std::system("PAUSE");

	

	line l;
	string in;
	int i = 0;
	int k = 0;
	string inputs[53];
	//CSV File created by Affectiva must be inserted here
	ifstream input(AffCSVPath);
	if (!input.is_open())
		std::cout << "Error: File Open" << '\n';
	try {
		while (input.good())
		{


			for (int i = 0; i<52; i++)
			{
				getline(input, inputs[i], ',');
			}
			getline(input, inputs[52], '\n');
			l.setvalues(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10], inputs[11], inputs[12], inputs[13], inputs[14], inputs[15], inputs[16], inputs[17], inputs[18], inputs[19], inputs[20], inputs[21], inputs[22], inputs[23], inputs[24], inputs[25], inputs[26], inputs[27], inputs[28], inputs[29], inputs[30], inputs[31], inputs[32], inputs[33], inputs[34], inputs[35], inputs[36], inputs[37], inputs[38], inputs[39], inputs[40], inputs[41], inputs[42], inputs[43], inputs[44], inputs[45], inputs[46], inputs[47], inputs[48], inputs[49], inputs[50], inputs[51], inputs[52]);
			vic.push_back(l);
			i++;
		}
	}
	catch (exception e)
	{
		input.close();
	}
	input.close();
	ifstream times(TimPath);
	if (!times.is_open())
		std::cout << "Error: File Open" << '\n';
	try {
		while (times.good())
		{
			getline(times, in, '\n');
			std::cout << in << endl;
			timestamps[k] = stod(in);
			in = "";
			k++;
		}
	}
	catch (exception e)
	{
		times.close();
	}
	times.close();
	cout << "Maximum emotions per Questions" << endl;
	for_each(vic.begin(), vic.end(), split);
	for_each(vic1.begin(), vic1.end(), reveal);
	displaymax(1);
	for_each(vic2.begin(), vic2.end(), reveal);
	displaymax(2);
	for_each(vic3.begin(), vic3.end(), reveal);
	displaymax(3);
	for_each(vic4.begin(), vic4.end(), reveal);
	displaymax(4);
	for_each(vic5.begin(), vic5.end(), reveal);
	displaymax(5);
	for_each(vic6.begin(), vic6.end(), reveal);
	displaymax(6);
	for_each(vic7.begin(), vic7.end(), reveal);
	displaymax(7);
	for_each(vic8.begin(), vic8.end(), reveal);
	displaymax(8);
	for_each(vic9.begin(), vic9.end(), reveal);
	displaymax(9);
	for_each(vic10.begin(), vic10.end(), reveal);
	displaymax(10);
	for_each(vic11.begin(), vic11.end(), reveal);
	displaymax(11);
	for_each(vic12.begin(), vic12.end(), reveal);
	displaymax(12);
	for_each(vic13.begin(), vic13.end(), reveal);
	displaymax(13);
	for_each(vic14.begin(), vic14.end(), reveal);
	displaymax(14);
	for_each(vic15.begin(), vic15.end(), reveal);
	displaymax(15);
	for_each(vic16.begin(), vic16.end(), reveal);
	displaymax(16);
	for_each(vic17.begin(), vic17.end(), reveal);
	displaymax(17);
	for_each(vic18.begin(), vic18.end(), reveal);
	displaymax(18);
	for_each(vic19.begin(), vic19.end(), reveal);
	displaymax(19);
	for_each(vic20.begin(), vic20.end(), reveal);
	displaymax(20);
	for_each(vic21.begin(), vic21.end(), reveal);
	displaymax(21);
	for_each(vic22.begin(), vic22.end(), reveal);
	displaymax(22);
	for_each(vic23.begin(), vic23.end(), reveal);
	displaymax(23);
	for_each(vic24.begin(), vic24.end(), reveal);
	displaymax(24);
	for_each(vic25.begin(), vic25.end(), reveal);
	displaymax(25);
	for_each(vic26.begin(), vic26.end(), reveal);
	displaymax(26);
	for_each(vic27.begin(), vic27.end(), reveal);
	displaymax(27);
	for_each(vic28.begin(), vic28.end(), reveal);
	displaymax(28);
	for_each(vic29.begin(), vic29.end(), reveal);
	displaymax(29);
	for_each(vic30.begin(), vic30.end(), reveal);
	displaymax(30);
	for_each(vic31.begin(), vic31.end(), reveal);
	displaymax(31);
	for_each(vic32.begin(), vic32.end(), reveal);
	displaymax(32);
	for_each(vic33.begin(), vic33.end(), reveal);
	displaymax(33);
	for_each(vic34.begin(), vic34.end(), reveal);
	displaymax(34);
	std::cout << "1. ";
	for (int i = 0; i < 7; i++)
	{
		std::cout << maxvalues[0][i] << endl;
	}


}

void EmpathProcess(string EmpPath, string TemPath)
{
	string parameter = "-jar C:\\Users\\LENOVO\\Desktop\\Thesis\\EMPATHCMS\\EmpathCMS2.jar 9_KjnGMlmjVaJLMphp4dJi4ZQoDKLoWWs-q9bsFPpB8 " + EmpPath + " "+TemPath;
	LPCSTR parameters = parameter.c_str();
	string extract;

	std::cout << "Opening Empath";

	std::system("PAUSE");

	//ShellExecuteA(NULL, "open", "C:\\Users\\daniel-hp\\Downloads\\eclipse-java-oxygen-2-win32-x86_64\\eclipse\\eclipse.exe", parameters, NULL, SW_SHOWMAXIMIZED);



	std::cout << "Runs Empath"<<endl;


	//C:\\Program Files\\Java\jdk-9.0.4\\bin\\java.exe
	ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Java\\jre1.8.0_181\\bin\\java.exe", parameters, NULL, SW_SHOWMAXIMIZED);
	std::system("PAUSE");
	ifstream tempfile;
	int n = 0;

	tempfile.open(TemPath);
	while (tempfile.good())
	{
		getline(tempfile, extract, '}');
		empathstring(extract, n);
		n++;
	}
	tempfile.close();
	combine();
	for (int i = 0; i < 34; i++)
	{
		int h = i + 1;
		std::cout << "No." << h;
		for (int j = 0; j < 11; j++)
		{
			std::cout << " " << combinedvalues[i][j];
		}
		std::cout << endl;
	}
	std::system("PAUSE");
	std::system("CLS");
}
void DatabaseInsert(string runcode)
{
	for (int i = 0; i < 34; i++)
	{
		int j = i + 1;
		Combined c(samplenum, j, combinedvalues[i][0], combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10]);
		d.insertData(runcode, c);
	}


}

string runcode(size_t length)
{
	srand(time(NULL));
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset)-1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}







int _tmain(int argc, _TCHAR* argv[])
{

	string run = runcode(8);
	cout << "This is your runcode: " << run << endl;
	std::cout << "Please Enter Sample Number" << endl;
	cin >> samplenum;

	string afpath = "";
	string tipath = "";
	string afpathcsv = "";
	string Empath = "";
	string Tepath = "";


	switch (samplenum){

	case 48:


		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview6\\20171013093357.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview6\\20171013093357.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 48.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number48\\Number48\\48";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);







		
		
		break;




	case 49:


		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview6\\20171013093936.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview6\\20171013093936.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 49.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number49\\Number49\\49";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);








		break;



	case 50:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073158.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073158.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 50.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number50\\Number50\\50";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);





		break;


	case 51:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073627.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073627.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 51.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number51\\Number51\\51";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);



		break;


	case 52:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073931.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073931.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 52.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number52\\Number52\\52";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);




		break;

	case 53:

			std::cout << "Please Enter Video Path" << endl;
			afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016074330.mp4\"  --numFaces \"2\" ";
			afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016074330.csv";
			std::cout << "Please Enter Timestamp" << endl;
			tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 53.txt";
			AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
			std::cout << "Please Enter Audio Path" << endl;
			Empath = "C:\\Users\\daniel-hp\\Documents\\Number53\\Number53\\53";
			std::cout << "Please Enter Temp Path" << endl;
			Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
			EmpathProcess(Empath, Tepath);
			std::system("PAUSE");
			DatabaseInsert(run);




			break;

	case 54:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016074734.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016074734.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 54.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number54\\Number54\\54";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);



		break;


	case 55:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075112.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075112.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 55.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number55\\Number55\\55";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);
		

		break;

	case 56:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075428.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075428.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 56.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number56\\Number56\\56";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);


		break;

	case 57 :

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075839.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016075839.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 57.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number57New\\Number57New\\57";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);


		break;

	case 58 :

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016080252.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016080252.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 58.txt";
		AffectivaProcess(afpath, tipath,afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Documents\\Number58\\Number58\\58";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";
		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;

	case 59 :

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016080633.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\LENOVO\\Desktop\\Thesis\\Interview\\CSV Files\\20171016080633.csv";
		std::cout << "Please Enter Timestamp" << endl;
	    tipath = "C:\\Users\\LENOVO\\Desktop\\Thesis\\Timestamps\\Sample 59.txt";
		AffectivaProcess(afpath, tipath,afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
	    Empath = "C:\\Users\\LENOVO\\Desktop\\Thesis\\Interview\\SegmentedCuts\\Number59\\59";
		std::cout << "Please Enter Temp Path" << endl;
	    Tepath = "C:\\Users\\LENOVO\\Desktop\\Thesis\\EMPATHCMS\\Temporary.txt";

		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;

	case 70:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628120735.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628120735.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 70.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Downloads\\RealEstateSegmentedCuts\\RealEstateSegmentedCuts\\Number11\\11";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";

		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;

	case 72:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628121728.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628121728.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 72.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Downloads\\RealEstateSegmentedCuts\\RealEstateSegmentedCuts\\Number13\\13";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";

		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;


	case 78:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628134924.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628134924.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 78.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Downloads\\RealEstateSegmentedCuts\\RealEstateSegmentedCuts\\Number19\\19";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";

		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;

	case 79:

		std::cout << "Please Enter Video Path" << endl;
		afpath = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628135449.mp4\"  --numFaces \"2\" ";
		afpathcsv = "C:\\Users\\daniel-hp\\Videos\\Interview8\\20180628135449.csv";
		std::cout << "Please Enter Timestamp" << endl;
		tipath = "C:\\Users\\daniel-hp\\Downloads\\Timestamps\\Timestamps\\Sample 79.txt";
		AffectivaProcess(afpath, tipath, afpathcsv);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
		std::cout << "Please Enter Audio Path" << endl;
		Empath = "C:\\Users\\daniel-hp\\Downloads\\RealEstateSegmentedCuts\\RealEstateSegmentedCuts\\Number20\\20";
		std::cout << "Please Enter Temp Path" << endl;
		Tepath = "C:\\Users\\daniel-hp\\Documents\\EMPATHPROTOCMS\\EmpathCMS3\\Temporary.txt";

		EmpathProcess(Empath, Tepath);
		std::system("PAUSE");
		DatabaseInsert(run);

		break;




	default :

		return 0;


	}

	double nnfailcount = 0;
	double nnsuccesscount = 0;


string origdec = "";

string deccom = "";

cout << "Use Combined(C) or Stand Alone(A)?" << endl;
cin >> deccom  ;

bool deccomlog = false;

if (deccom == "C")

deccomlog = true;

else if (deccom == "A")

deccomlog = false;


string finalpath = "";

string newcsv = "";
string inputarff = "";
string j48Model = "";
string nnModel = "";
string svmModel = "";
string nbModel = "";
string output = "";


switch (samplenum){


case 48:


	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 48.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 48.csv";


		origdec = "Fail";
	}



	break;

case 49:


	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);


	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 49.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 49.csv";


		origdec = "Fail";
	}




	break;


case 50:

	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 50.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 50.csv";


		origdec = "Fail";
	}



	break;


case 51:

	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 51.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 51.csv";


		origdec = "Fail";
	}




	break;



case 52:

	if (deccomlog == false)
	{



	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 52.csv";

	origdec = "Sucess";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 52.csv";


		origdec = "Success";
	}



	break;




case 53:


	if (deccomlog == false)
	{

	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);


	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 53.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 53.csv";


		origdec = "Fail";
	}


	break;


case 54:


	if (deccomlog == false)
	{

	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 54.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 54.csv";


		origdec = "Fail";
	}


	break;


case 55:

	if (deccomlog == false)
	{

	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 55.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 55.csv";


		origdec = "Fail";
	}




	break;



case 56:

	if (deccomlog == false)
	{

	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);


	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 56.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 56.csv";


		origdec = "Fail";
	}





	break;



case 57:


	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 57.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 57.csv";


		origdec = "Fail";
	}




	break;


case 58:


	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 58.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 58.csv";


		origdec = "Fail";
	}



	break;

case 59:

	if (deccomlog == false)
	{


	 newcsv = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\NewCSV.csv";
	 inputarff = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\NewCSV.arff";
	newCSV(newcsv);
	 j48Model = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\J48Model.model";
	 nnModel = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\NNModel.model";
	 svmModel = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\SVMModel.model";
	 nbModel = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\NBModel.model";
	 output = "C:\\Users\\LENOVO\\Desktop\\Thesis\\MRAD\\Output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\MRAD\\MRAD\\MedRepFinalOutput 59.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\CombinedData\\CombinedDatasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 59.csv";


		origdec = "Fail";
	}



	break;

case 70:

	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\RealEstateFinalOutput 70.csv";

	origdec = "Success";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 70.csv";


		origdec = "Success";
	}


	break;



case 72:

	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\RealEstateFinalOutput 72.csv";

	origdec = "Success";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 72.csv";


		origdec = "Success";
	}

	break;


case 78:


	if (deccomlog == false)
	{


	newcsv = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.csv";
	inputarff = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.arff";
	newCSV(newcsv);
	j48Model = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\J48Model.model";
	nnModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NNModel.model";
	svmModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\SVMModel.model";
	nbModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NBModel.model";
	output = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\output.csv";
	WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

	modelPredictions(output);

	finalpath = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\RealEstateFinalOutput 78.csv";

	origdec = "Fail";

	}

	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 78.csv";


		origdec = "Fail";
	}



	break;

case 79:

	if (deccomlog == false)
	{


		newcsv = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output);

		 finalpath = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\RealEstateFinalOutput 79.csv";

		 origdec = "Fail";

	}
	 
	else if (deccomlog == true)
	{

		newcsv = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.csv";
		inputarff = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NewCSV.arff";
		newCSV(newcsv);
		j48Model = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\J48Model.model";
		nnModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NNModel.model";
		svmModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\SVMModel.model";
		nbModel = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\NBModel.model";
		output = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\output.csv";
		WekaModelApplication(newcsv, inputarff, j48Model, nnModel, svmModel, nbModel, output);

		modelPredictions(output); 

		finalpath = "C:\\Users\\daniel-hp\\Downloads\\Combined Data\\Combined Datasets\\CombinedFinalOutput 79.csv";


		origdec = "Fail";
	}

	

	break;

		default:

	return 0;


}

	int NNSuccess = 0;
	int NNFail = 0;
	int NBSuccess = 0;
	int NBFail = 0;
	string NBfinaldecision;
	int J48Success = 0;
	int J48fail = 0;
	string J48finaldecision;
	int SVMSuccess = 0;
	int SVMfail = 0;
	string SVMfinaldecision;
	int g = 1;
	string dec1;
	string dec2;
	string dec3;
	string dec4;


	for (int i = 0; i < 34 ; i++, g++)
	{

		dec1 = predictions[i][0];
		dec2 = predictions[i][1];
		dec3 = predictions[i][2];
		dec4 = predictions[i][3];

		cout << g << ". J48: " << dec1 << " NN: " << dec2 << " SVM: " << dec3 << " NB: " << dec4 << endl;
		d.insertResult(run, samplenum, g, dec1, dec2, dec3, dec4);
		if (dec1 == "High")
			J48Success++;
		else
			J48fail++;
		if (dec2 == "High")
			NNSuccess++;
		else
			NNFail++;
		if (dec3 == "High")
			SVMSuccess++;
		else
			SVMfail++;
		if (dec4 == "High")
			NBSuccess++;
		else
			NBFail++;

		
	}


	if (NBSuccess > NBFail)
		NBfinaldecision = "SUCCESS";
	else
		NBfinaldecision = "FAIL";
	if (SVMSuccess > SVMfail)
		SVMfinaldecision = "SUCCESS";
	else
		SVMfinaldecision = "FAIL";
	if (J48Success > J48fail)
		J48finaldecision = "SUCCESS";
	else
		J48finaldecision = "FAIL";
	double nsucmean = nsucsum / 34;
	double nfaimean = nfaisum / 34;
	string NNfinaldecision;
	if (nsucmean > nfaimean)
		NNfinaldecision = "SUCCESS";


	else
		NNfinaldecision = "FAIL";
	std::cout << "Final Decision: NB: " << NBfinaldecision << " SVM: " << SVMfinaldecision << " J48: " << J48finaldecision << " NN: " << NNfinaldecision;
	
	double NBpercentSuc = (NBSuccess*100) / 34;
	double NBpercentFai = (NBFail*100) / 34;
	double SVMpercentSuc = (SVMSuccess*100) / 34;
	double SVMpercentFai = (SVMfail*100) / 34;
	double J48percentSuc = (J48Success*100) / 34;
	double J48percentFai = (J48fail*100) / 34;	
	double NNpercentSuc = (NNSuccess * 100) / 34;
	double NNpercentFai = (NNFail * 100) / 34;



	string NBsucclas = "";
	string SVMsucclas = "";
	string J48succlas = "";
	string NNsucclas = "";

	bool NBsucclasb = false;
	bool SVMsucclasb = false;
	bool J48succlasb = false;
	bool NNsucclasb = false;


	double perclassuc = 0;

	double maxsuc = max(max(NBpercentSuc, SVMpercentSuc), max(J48percentSuc, NNpercentSuc));



	if (maxsuc==NBpercentSuc)

	{
		NBsucclas = "Naive Bayes";
		NBsucclasb = true;
	}
	if (maxsuc==SVMpercentSuc)

	{
		SVMsucclas = "SVM";
		SVMsucclasb = true;

	}
	if (maxsuc == J48percentSuc)

	{
		J48succlas = "J48";
		J48succlasb = true;
	}

	if (maxsuc == NNpercentSuc)

	{
		NNsucclas = "NN";
		NNsucclasb = true;

	}
	string NBfalclas = "";
	string SVMfalclas = "";
	string J48falclas = "";
	string NNfalclas = "";

	bool NBfalclasb = false;
	bool SVMfalclasb = false;
	bool J48falclasb = false;
	bool NNfalclasb = false;

	double perclasfai = 0;

	double maxfai = max(max(NBpercentFai, SVMpercentFai), max(J48percentFai, NNpercentFai));

	if (maxfai == NBpercentFai)
	{

		NBfalclas = "Naive Bayes";
		NBfalclasb = true;

	}
	if (maxfai == SVMpercentFai)
	{

		SVMfalclas = "SVM";
		SVMfalclasb = true;
	}
	if (maxfai == J48percentFai)
	{

		J48falclas = "J48";
		J48falclasb = true;
	}

	if (maxfai == NNpercentFai)

	{


		NNfalclas = "NN";
		NNfalclasb = true;



	}

	/*
	

	string finsamnum = "0";

	switch (samplenum) {

	case 48:

		finsamnum = "48";

		break;




	case 49:

		finsamnum = "49";

		break;



	case 50:

		finsamnum = "50";

		break;




	case 51:

		finsamnum = "51";

		break;





	case 52:

		finsamnum = "52";

		break;





	case 53:

		finsamnum = "53";

		break;




	case 54:

		finsamnum = "54";

		break;




	case 55:

		finsamnum = "55";

		break;




	case 56:

		finsamnum = "56";

		break;




	case 57:

		finsamnum = "57";

		break;



	case 58:

		finsamnum = "58";

		break;

	case 59:

		finsamnum = "59";

		break;

	case 70:

		finsamnum = "70";

		break;


	case 72:

		finsamnum = "72";

		break;


	case 78:

		finsamnum = "78";

		break;


	case 79:

		finsamnum = "79";

		break;


	default:

		return 0;

	}




	string finalpath = "C:\\Users\\daniel-hp\\Downloads\\REED\\REED\\MedRepFinalOutput " + finsamnum + ".csv";


	*/
	ofstream finaldata;
	 
	finaldata.open(finalpath);

	
	std::cout << "\nClassification of Sample is " << origdec << endl;
	std::cout <<"\n" << "NB: Success" << " : "<<NBSuccess << " : " << NBpercentSuc << "%"  << endl;
	std::cout << "SVM: Success" << " : " <<SVMSuccess << " : " << SVMpercentSuc << "%" << endl;
	std::cout << "J48: Success" << " : " << J48Success << " : " <<J48percentSuc << "%"  << endl;
	std::cout << "NN: Success" << " : " << NNSuccess << " : " << NNpercentSuc << "%" << endl;

	std::cout << "NB: Fail" << " : " << NBFail << " : " << NBpercentFai << "%" << endl;
	std::cout << "SVM: Fail" << " : " << SVMfail << " : " << SVMpercentFai  << "%" << endl;
	std::cout << "J48: Fail" << " : " << J48fail << " : " << J48percentFai << "%"  << endl;
	std::cout << "NN: Fail" << " : " << NNFail << " : " << NNpercentFai << "%" << endl;

	finaldata << "Classification of Sample is " << origdec << endl;

	finaldata << "\n" << "NB: Success" << " : " << NBSuccess << " : " << NBpercentSuc << "%" << endl;
	finaldata << "SVM: Success" << " : " << SVMSuccess << " : " << SVMpercentSuc << "%" << endl;
	finaldata << "J48: Success" << " : " << J48Success << " : " << J48percentSuc << "%" << endl;
	finaldata << "NN: Success" << " : " << NNSuccess << " : " << NNpercentSuc << "%" << endl;

	finaldata << "NB: Fail" << " : " << NBFail << " : " << NBpercentFai << "%" << endl;
	finaldata << "SVM: Fail" << " : " << SVMfail << " : " << SVMpercentFai << "%" << endl;
	finaldata << "J48: Fail" << " : " << J48fail << " : " << J48percentFai << "%" << endl;
	finaldata << "NN: Fail" << " : " << NNFail << " : " << NNpercentFai << "%" << endl;



	if (NBsucclasb == true)

	{
		std::cout << "Best Classifier success is " << NBsucclas << " with " << NBpercentSuc << "%" << endl;
		finaldata << "Best Classifier success is " << NBsucclas << " with " << NBpercentSuc << "%" << endl;

	}

	if (SVMsucclasb == true)
	{

		std::cout << "Best Classifier success is " << SVMsucclas << " with " << SVMpercentSuc << "%" << endl;
		finaldata << "Best Classifier success is " << SVMsucclas << " with " << SVMpercentSuc << "%" << endl;
	}
	if (J48succlasb == true)

	{


		std::cout << "Best Classifier success is " << J48succlas << " with " << J48percentSuc << "%" << endl;
		finaldata << "Best Classifier success is " << J48succlas << " with " << J48percentSuc << "%" << endl;
	}
	if (NNsucclasb == true)

	{

		std::cout << "Best Classifier success is " << NNsucclas << " with " << NNpercentSuc << "%" << endl;
		finaldata << "Best Classifier success is " << NNsucclas << " with " << NNpercentSuc << "%" << endl;


	}

	
	if (NBfalclasb == true)

	{

		std::cout << "Best Classfier fail is " << NBfalclas << " with " << NBpercentFai << "%" << endl;
		finaldata << "Best Classfier fail is " << NBfalclas << " with " << NBpercentFai << "%" << endl;


	}
	if (SVMfalclasb == true)

	{

		std::cout << "Best Classfier fail is " << SVMfalclas << " with " << SVMpercentFai << "%" << endl;
		finaldata << "Best Classfier fail is " << SVMfalclas << " with " << SVMpercentFai << "%" << endl;

	}

	if (J48falclasb == true)
	{

		std::cout << "Best Classfier fail is " << J48falclas << " with " << J48percentFai << "%" << endl;
		finaldata << "Best Classfier fail is " << J48falclas << " with " << J48percentFai << "%" << endl;


	}
	if (NNfalclasb == true)

	{



		std::cout << "Best Classfier fail is " << NNfalclas << " with " << NNpercentFai << "%" << endl;
		finaldata << "Best Classfier fail is " << NNfalclas << " with " << NNpercentFai << "%" << endl;



	}
	finaldata.close();

	std::system("PAUSE");
	

	return 0;
}

