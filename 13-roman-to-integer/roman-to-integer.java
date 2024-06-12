class Solution {
    
    public int romanToInt(String s) 
    {
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            char ch1 = s.charAt(i);
            // converting character to decimal
            int num1 = Roman_To_Decimal(ch1);
            if(i+1 < s.length())
            {
                char ch2 = s.charAt(i+1);
                int num2 = Roman_To_Decimal(ch2);
                
                // comparing the two adjacent numerals
                if(num1 >= num2)
                {
                    result = result + num1;
                }
                else
                {
                    result = result + num2 - num1;
                    i++;
                }
            }
            else
            {
                result = result + num1;
            }

        }
        // returning the result
        return result;
    }
    
    static int Roman_To_Decimal(char value)
    {
        if(value == 'I')
            return 1;
        else if(value == 'V')
            return 5;
        else if(value == 'X')
            return 10;
        else if(value == 'L')
            return 50;
        else if(value == 'C')
            return 100;
        else if(value == 'D')
            return 500;
        else if(value == 'M')
            return 1000;

        return -1;
    }
}