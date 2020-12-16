# collision-detection
当たり判定の関数です。ご自由にお使いください。

Vec2:位置ベクトルや普通のベクトル(?)を表すのに使います。要は「floatの値２つ」です。
Line:線分です。２つのVec2は端点を表します。「Vec2を２つ」。
何やらいろいろ関数が書いてありますが、使ってほしいのはCross_Line_h関数です。
始点->終点方向に線分を見たとき、左側からの衝突を検知し、壁ずりベクトルなどを考慮したうえで次に移動すべき点をVec2で返します。

void Cross_Line_h(Line d_l,Line b,bool* TF,Vec2* p){...}
「d_l」...始点(前フレームの点の位置),終点(後フレームの点の位置)である線分。
「b」  ...障害物となる線分。
「TF」 ...衝突した場合true,衝突しなかった場合falseが入ります。
「p」  ...計算で、移動すべき座標が入れられます。

現在この関数は、線分をつないだ場合、凸な図形でないと頂点で貫通することがあります。
今後更新していきます。(最終更新:2020年12月16日(水))

      使い方の例:
      
      bool TF;                                            //TRUE FALSE
			Vec2 zahyou(0.0f, 0.0f);                            //移動すべき座標が入れられる    
      
			Cross_Line_h(move_line, obj_line, &TF, &kouten);    //移動すべき座標を計算
			if (TF) {                                           //もし衝突していたら
				player.x = zahyou.x;                              //計算した座標を代入(x)
        player.y = zahyou.y;                              //計算した座標を代入(y)
			}
