import java.util.Scanner;

class CamelCase4 {
    public char method;
    public char operation;
    public String text;

    public char getMethod() {
        return method;
    }

    public void setMethod(char method) {
        this.method = method;
    }

    public char getOperation() {
        return operation;
    }

    public void setOperation(char operation) {
        this.operation = operation;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String strip() {
        String tmp = "";

        if (method == 'C')
            text = text.substring(0, 1).toLowerCase() + text.substring(1);
        else if (method == 'M') {
            text = text.substring(0, 1).toLowerCase() + text.substring(1, text.length() - 2);
        }

        for (int i = 0; i < text.length(); i++) {
            char letter = text.charAt(i);
            if (Character.isUpperCase(letter)) {
                tmp += " " + text.toLowerCase().charAt(i);
            } else if (text.charAt(i) != ' ') {
                tmp += text.charAt(i);
            }
        }

        return tmp;
    }

    public String combine() {
        String tmp = "";

        if (method == 'C')
            text = text.substring(0, 1).toUpperCase() + text.substring(1);
        else if (method == 'M')
            text += "()";

        tmp += text.charAt(0);

        for (int i = 1; i < text.length(); i++) {
            if (text.charAt(i - 1) == ' ') {
                tmp += text.toUpperCase().charAt(i);
            } else if (text.charAt(i) != ' ') {
                tmp += text.charAt(i);
            }
        }

        return tmp;
    }

    public String conversor() {
        String newText = "";

        if (operation == 'S')
            newText = strip();
        else if (operation == 'C')
            newText = combine();

        return newText;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            int length = input.length();

            CamelCase4 solution = new CamelCase4();
            solution.setOperation(input.charAt(0));
            solution.setMethod(input.charAt(2));
            solution.setText(input.substring(4, length));

            String output = solution.conversor();
            System.out.println(output);
        }

        scanner.close();
    }
}