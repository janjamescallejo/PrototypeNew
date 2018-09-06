/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



package j48modelapplication;
import weka.classifiers.trees.J48;
import weka.core.Instances;
import java.util.Random;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import weka.core.converters.ArffSaver;
import weka.core.converters.CSVLoader;
import java.io.FileInputStream;
import weka.classifiers.Evaluation;
import weka.core.SerializationHelper;
import java.io.File;
/**
 *
 * @author Lenovo
 */
public class J48ModelApplication {

    /**
     * @param args the command line arguments
     */
    public static void J48Test (Instances test,String model)throws Exception
    {
        J48 j48;
      j48= (J48)(SerializationHelper.read(new FileInputStream(model)));
      System.out.println(j48.prefix());
      BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\Users\\daniel-hp\\Downloads\\CMSPrototypeNew\\J48Results.csv"));
      Evaluation eval=new Evaluation(test);
      //eval.evaluateModelOnce(j48, test.firstInstance());
      eval.useNoPriors();
      System.out.println(eval.toMatrixString());
      for(int i=0;i<34;i++)
      {
          eval.evaluateModelOnce(j48, test.get(i));
          if(eval.confusionMatrix()[0][0]==1||eval.confusionMatrix()[1][0]==1)
          {
            writer.write("Low");
             writer.newLine();
              System.out.println("Low");
          }
          else
          {
               writer.write("High");
             writer.newLine();
              System.out.println("High");
          }
      }
      writer.close();
      /*eval.evaluateModel(j48, test);
      System.out.println(eval.toSummaryString("\n Results \n=====\n",true));
      System.out.println("Actual Low and Predicted Low: "+eval.confusionMatrix()[0][0]);
      System.out.println("Actual Low and Predicted High: "+eval.confusionMatrix()[0][1]);
      System.out.println("Actual High and Predicted Low: "+eval.confusionMatrix()[1][0]);
      System.out.println("Actual High and Predicted High: "+eval.confusionMatrix()[1][1]);
      System.out.println(eval.toMatrixString());
      System.out.println(eval.toClassDetailsString());*/
    }
    public static void main(String[] args) throws Exception{
     System.out.println("Opening and Testing J48");
        CSVLoader loader = new CSVLoader();
      loader.setSource(new File("C:\\Users\\daniel-hp\\Downloads\\CMSPrototypeNew\\PrototypeTester.csv"));
      Instances data = loader.getDataSet();
      data.setClassIndex(11);
       ArffSaver saver = new ArffSaver();
    saver.setInstances(data);
    saver.setFile(new File("C:\\Users\\daniel-hp\\Downloads\\CMSPrototypeNew\\PrototypeTester.arff"));
    saver.writeBatch();
    J48Test(data,"C:\\Users\\daniel-hp\\Downloads\\CMSPrototypeNew\\J48.model");
        
    }
    
}
