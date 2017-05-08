uniform vec2 resolution;
uniform sampler2DRect _texture;
uniform float coef[9];

const float redScale   = 0.298912;
const float greenScale = 0.586611;
const float blueScale  = 0.114478;
const vec3  monochromeScale = vec3(redScale, greenScale, blueScale);


void main(){
    vec2 offset[9];
    offset[0] = vec2(-1.0, -1.0);
    offset[1] = vec2( 0.0, -1.0);
    offset[2] = vec2( 1.0, -1.0);
    offset[3] = vec2(-1.0,  0.0);
    offset[4] = vec2( 0.0,  0.0);
    offset[5] = vec2( 1.0,  0.0);
    offset[6] = vec2(-1.0,  1.0);
    offset[7] = vec2( 0.0,  1.0);
    offset[8] = vec2( 1.0,  1.0);
    
    vec2  fc = vec2(gl_TexCoord[0].x, gl_TexCoord[0].y);
    vec3  destColor = vec3(0.0);
    
    destColor += texture2DRect(_texture, (fc + offset[0])).rgb * coef[0];
    destColor += texture2DRect(_texture, (fc + offset[1])).rgb * coef[1];
    destColor += texture2DRect(_texture, (fc + offset[2])).rgb * coef[2];
    destColor += texture2DRect(_texture, (fc + offset[3])).rgb * coef[3];
    destColor += texture2DRect(_texture, (fc + offset[4])).rgb * coef[4];
    destColor += texture2DRect(_texture, (fc + offset[5])).rgb * coef[5];
    destColor += texture2DRect(_texture, (fc + offset[6])).rgb * coef[6];
    destColor += texture2DRect(_texture, (fc + offset[7])).rgb * coef[7];
    destColor += texture2DRect(_texture, (fc + offset[8])).rgb * coef[8];
    
//    destColor = max(destColor, 0.0);
    
    //    float grayColor = dot(destColor, monochromeScale);
    //    destColor = vec3(grayColor);
    gl_FragColor = vec4(destColor, 1.0);
    
    
}