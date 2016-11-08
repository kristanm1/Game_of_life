import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

//Obdelaj.java predela podatke v obliko primerno za funkcijo parametri(x, y, model, k)
//yyyy-MM-dd;value
//2000-12-31;value => 2000 + 365/365 value = 2001 value
//2000-12-31;value => 2001 value

public class Obdelaj {
	
	private static int getDayOfYear(String dateString) throws ParseException{
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		Date date = sdf.parse(dateString);
		GregorianCalendar greg = new GregorianCalendar();
		greg.setTime(date);
		return greg.get(greg.DAY_OF_YEAR);
	}

	private static double prestopno(String leto) {
		int year = Integer.valueOf(leto);
		if(((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))) {
			return 366.0;
		}
		return 365.0;
	}
	
	private static void preberi(String input, String output) throws IOException {
		
		Scanner sc = new Scanner(new File(input));
		FileWriter f = new FileWriter(output);
		
		String line;
		while(sc.hasNext()) {
			line = sc.nextLine();
			String[] data = line.split(";");
			try {
				double d = (double) getDayOfYear(data[0]) / prestopno(line.split("-")[0]);
				System.out.println(d + Integer.valueOf(line.split("-")[0]) +" "+data[1]+" "+Double.valueOf(data[1]));
				String out = String.format("%6.6e", d + Integer.valueOf(line.split("-")[0]));
				if(Double.valueOf(data[1]) > 0) {
					f.write(out+" "+data[1]+"\t\n");
				}
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		f.close();
	}
	
	public static void main(String[] args) throws IOException {
		
		try {
			preberi("C:\\Users\\Matej\\Desktop\\MM\\Naloga1\\mauna_lua.txt",
					"C:\\Users\\Matej\\Desktop\\MM\\Naloga1\\data.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
	
}
