package com.personal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader reader = null;

    public static void main(String[] args) {


        while (true) {
            System.out.println("(1) to test hashFunction");
            System.out.println("Anything else to exit");
            System.out.print("Enter option : ");

            reader = new BufferedReader(new InputStreamReader(System.in));
            try {
                int option = Integer.parseInt(reader.readLine());
                switch (option) {
                    case 1: testHash(); break;
                    default: System.exit(0);
                }
            } catch (Exception e) {
                System.err.println(e);
                System.exit(1);
            }
        }
    }

    private static void testHash() throws IOException {
        System.out.print("Enter string : ");
        String inp = reader.readLine();
        TestPojo pojo = new TestPojo(inp);
        System.out.println("Hash code is : " + inp.hashCode());
    }
}
