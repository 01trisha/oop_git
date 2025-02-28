package org.example;

import java.io.*;
import java.util.HashMap;

public class ReaderTxt {
    private final String path_to_file;

    public ReaderTxt(String path) {
        if (!path.endsWith(".txt")) {
            throw new IllegalArgumentException("The file must have a .txt extension");
        }
        path_to_file = path;
    }

    public HashMap<String, Integer> readTxt() {
        try(Reader input = new InputStreamReader(new FileInputStream(path_to_file))){

            HashMap<String, Integer> wordCountMap = new HashMap<>();
            int character;
            StringBuilder currentWord = new StringBuilder();

            while ((character = input.read()) != -1) {
                char c = (char) character;
                if (Character.isLetterOrDigit(c)) {
                    currentWord.append(c);
                } else {
                    if (!currentWord.isEmpty()) {
                        String word = currentWord.toString()/*.toLowerCase()*/;
                        wordCountMap.put(word, wordCountMap.getOrDefault(word, 0) + 1);
                        currentWord.setLength(0);
                    }
                }
            }
            //обработка последнего слова
            if (!currentWord.isEmpty()) {
                String word = currentWord.toString()/*.toLowerCase()*/;
                wordCountMap.put(word, wordCountMap.getOrDefault(word, 0) + 1);

            }
            return wordCountMap;
        }catch(IOException e) {
            throw new RuntimeException("Error reading file", e);
        }
    }
}
