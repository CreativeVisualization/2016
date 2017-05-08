uniform vec2 resolution;
uniform sampler2DRect _texture;
uniform float _min;

void main(){
    vec2 uv = gl_FragCoord.xy;
    vec4 imageColor = texture2DRect(_texture, uv);
    
    float min = _min;
    if (imageColor.r > min && imageColor.g > min && imageColor.b > min) { //白を抽出
        imageColor.a = 0.;
    }else{
        imageColor = vec4(1.);
    }
    gl_FragColor = vec4(imageColor);
}