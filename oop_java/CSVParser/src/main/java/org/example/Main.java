package org.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
public static void main(String[] args) {
    try {
        if (args.length != 1) {
            throw new Exception("Invalid number of arguments, usage: java -jar main.jar <file>");
        }

        String path = args[0];
        ReaderTxt readerTxt = new ReaderTxt(path);
        HashMap<String, Integer> words;

        words = readerTxt.readTxt();
        int countWords = words.values().stream().mapToInt(Integer::intValue).sum();

//        int countWords = 0;
//        for (int count : words.values()) {
//            countWords += count;
//        }

        Map<String, Double> percent = new HashMap<>();
        for(Map.Entry<String, Integer> entry : words.entrySet()) {
            double percentage = (double) entry.getValue() / countWords * 100;
            percent.put(entry.getKey(), percentage);
        }

        List<Map.Entry<String, Integer>> sortedWordstoList = new ArrayList<>(words.entrySet());
        sortedWordstoList.sort(Map.Entry.<String, Integer>comparingByValue().reversed());

        WriterCSV writer = new WriterCSV();

        writer.writeToCSV(sortedWordstoList, percent);

    }catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            System.exit(1);
        }
    }
}
