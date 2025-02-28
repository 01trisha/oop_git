package org.example;

import java.io.*;
import java.util.List;
import java.util.Map;

public class WriterCSV {

    public void writeToCSV(List<Map.Entry<String, Integer>> sortedList, Map<String, Double> percentMap){
        try(Writer writer = new OutputStreamWriter(new FileOutputStream("output.csv"))) {
            writer.write("Слово; Частота; Частота в %\n");
            for (Map.Entry<String, Integer> entry : sortedList) {
                String key = entry.getKey();
                int value = entry.getValue();
                double percentage = percentMap.get(key);
                writer.write(String.format("%s;%d;%.2f\n", key, value, percentage));
            }
        }catch (IOException e) {
            throw new RuntimeException("Error writing to file", e);
        }
    }
}
