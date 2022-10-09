//Group all anagrams together given a list of words
package Khatter_Mam;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PS_12 {
public static void main(String[] args) {
	ArrayList<String> collection = new ArrayList<String>();
//	ArrayList<ArrayList<String>> ans = new ArrayList<>();
	Scanner scn = new Scanner(System.in);
	int size = scn.nextInt();
	for(int i = 0; i < size; i++) {
		String str = scn.next();
		collection.add(str);
	}
	System.out.println(group(collection));
	
	
}

public static ArrayList<ArrayList<String>> group(ArrayList<String> collection) {
	ArrayList<ArrayList<String>> result = new ArrayList<>();
	Map<String, ArrayList<String>> group = new HashMap<String, ArrayList<String>>();
	
	for(int i =0; i < collection.size(); i++) {
		String str = collection.get(i);
		String strKey = buildAnagramKey(str);
	
	if(!group.containsKey(strKey)) {
		group.put(strKey, new ArrayList<String>());
	}
	group.get(strKey).add(str);
	}
	 for (Map.Entry<String, ArrayList<String>> pair : group.entrySet()){
         result.add(pair.getValue());
     }
	 return result;
}

public static String buildAnagramKey(String str) {
	int[] map = new int[26];
	for(Character c : str.toCharArray()) {
		map[c - 'a'] += 1;
	}
	
	StringBuilder build = new StringBuilder();
	for(int i = 0; i < 26; i++) {
		build.append(map[i]);
		build.append((char) i+'a');
	}
	return build.toString();
}
}
