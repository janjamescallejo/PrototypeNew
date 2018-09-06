My Revision notes towards the Prototype are as follows: 

"-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input \"C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073931.mp4\"  --numFaces \"2\" "


string input= "C:\\Users\\daniel-hp\\Videos\\Interview7\\20171016073931";
    string videopath = "\"" +input+".mp4\"";
    string csvpath = input+".csv";
    string parameter = "-d \"C:\\Program Files\\Affectiva\\Affdex SDK\\data\"  --input "+videopath+"  --numFaces \"2\" ";
    cout<<parameter<<endl;
    cout<<videopath<<endl;
    cout<<csvpath<<endl;

WekaModelImplementation.jar CSVFile, ArffFile, J48.Model, SVM.Model, NN.Model, NB.Model, results.csv

The arguments to make the WekaModelImplementation.jar file to run are as follows:

C:\Users\Lenovo\Desktop\Thesis\MRAD\NewCSV.csv C:\Users\Lenovo\Desktop\Thesis\MRAD\NewCSV.arff C:\Users\Lenovo\Desktop\Thesis\MRAD\J48.model C:\Users\Lenovo\Desktop\Thesis\MRAD\NN.model C:\Users\Lenovo\Desktop\Thesis\MRAD\SVM.model C:\Users\Lenovo\Desktop\Thesis\MRAD\NB.model C:\Users\Lenovo\Desktop\Thesis\MRAD\Output.csv 

Database Schema for Result and Final Data

Result: Runcode text, Sample Number int, Question Number int, J48 Decision text, NN Decision text, SVM Decision text, NB Decision text
Final Data: Runcode text, Sample Number int, Question Number int,[Affectiva Emotions] real, [Empath Emotions] int
