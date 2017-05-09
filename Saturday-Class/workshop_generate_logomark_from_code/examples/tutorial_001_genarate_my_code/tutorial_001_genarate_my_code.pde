String myName = "MASAKIYAMABE";
String myCode = "";
int myNameLength = myName.length();

for(int i =0; i<myNameLength; i++){
 char character = myName.charAt(i);
 int characterCode = int(character);
 println(character + ":"+characterCode);
 myCode += str(characterCode);
}

println("------");
println("myCode is "+myCode);