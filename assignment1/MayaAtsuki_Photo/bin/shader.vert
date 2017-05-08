uniform float texelWidth;
uniform float texelHeight;

varying vec2 textureCoordinate;
varying vec2 leftTextureCoordinate;
varying vec2 rightTextureCoordinate;

varying vec2 topTextureCoordinate;
varying vec2 topLeftTextureCoordinate;
varying vec2 topRightTextureCoordinate;

varying vec2 bottomTextureCoordinate;
varying vec2 bottomLeftTextureCoordinate;
varying vec2 bottomRightTextureCoordinate;

void main() {
    //gl_Position = position;
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    
    vec2 widthStep = vec2(texelWidth, 0.0);
    vec2 heightStep = vec2(0.0, texelHeight);
    vec2 widthHeightStep = vec2(texelWidth, texelHeight);
    vec2 widthNegativeHeightStep = vec2(texelWidth, -texelHeight);
    
    //textureCoordinate = inputTextureCoordinate.xy;
    textureCoordinate = vec2(gl_MultiTexCoord0);
    leftTextureCoordinate = textureCoordinate - widthStep;
    rightTextureCoordinate = textureCoordinate + widthStep;
    
    topTextureCoordinate = textureCoordinate - heightStep;
    topLeftTextureCoordinate = textureCoordinate - widthHeightStep;
    topRightTextureCoordinate = textureCoordinate + widthNegativeHeightStep;
    
    bottomTextureCoordinate = textureCoordinate + heightStep;
    bottomLeftTextureCoordinate = textureCoordinate - widthNegativeHeightStep;
    bottomRightTextureCoordinate = textureCoordinate + widthHeightStep;
}