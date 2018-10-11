# 我自己弄的游戏设计

## 游戏名称：绝地反击之穿越火线

### 游戏策划

#### 概念concept

##### 1. 楔子（Setting）
    2500年，人类发展出外太空生存技术后，再也无法满足地球的资源，开始了太空殖民；外星人我族人被人类的宇宙飞船逐出家园、赶尽杀绝，眼看我被包围陷入了危机，我要杀出重围！

##### 2. 玩法（Gameplay）
    玩家杀死飞船记一分。玩家被杀游戏结束。玩家使用方向键避让飞来的飞船与子弹，用鼠标瞄准左键发射火球

##### 3. 人设与道具（Game Sprites）
    1. Player：
    玩家，面包人。有五条生命值，可以抵挡五次敌人的子弹，但与敌人相撞立即爆炸死亡。可以360度旋转，八方向移动，连续无限量的朝鼠标方向发射火球。
![](http://thyrsi.com/t6/386/1539252236x-1566688347.png)
    
    2. Spaceship：
    敌人，宇宙飞船。初始九个，每3秒生成一个。有五条生命值，可以抵挡五次面包人的火球，但与面包人和其他敌人相撞立即爆炸死亡。一直朝面包人飞行，且持续无限量发射子弹。
![](http://thyrsi.com/t6/386/1539252475x-1566688526.png)
    
    3. Bullet：子弹。由敌人发出，碰到面包人与火球都会爆炸消失
![](http://thyrsi.com/t6/386/1539252571x1822611383.png)
    
    4. Fireball：火球。由面包人发出
![](http://thyrsi.com/t6/386/1539252592x1822611383.png)

##### 4. 基本规则（Basic rules）
    存活下去并尝试击败更多敌人！

##### 5. 游戏预览
![](http://thyrsi.com/t6/386/1539252050x-1376440138.gif)

### 游戏设计小结

#### CRC

| Object name | Player |
| - | - |
| Attributes | ![](http://thyrsi.com/t6/386/1539252236x-1566688347.png) |
| Collaborator | Events & Actions |
| 精灵 | 键盘移动
| | 点击鼠标左键发射火球
| | 头朝鼠标
| | Health = 5
| | 与子弹相撞，扣一条命
| | Health<=0，爆炸&销毁自己
| | 与Spaceship相撞，爆炸&销毁自己

| Object name | Spaceship |
| - | - |
| Attributes | ![](http://thyrsi.com/t6/386/1539252475x-1566688526.png) |
| Collaborator | Events & Actions |
| 精灵 | 时刻移动 |
| | 方向朝着Player |
| | Health = 5 |
| | 每2.5秒发射子弹 |
| | 与火球相撞，Health - 1 |
| | 与其他Spaceship或Player相撞，爆炸&销毁自己 |
| | Health <= 0，爆炸&销毁自己，分数 + 1 |
| | 每3秒随机地方产生一个新的Spaceship |

| Object name | Bullet |
| - | - |
| Attributes | ![](http://thyrsi.com/t6/386/1539252571x1822611383.png) |
| Collaborator | Events & Actions |
| 精灵 | 笔直飞行 |
| | 与Player和Fireball相撞，爆炸&销毁自己 |
| | 飞出游戏布局，销毁自己 |

| Object name | Fireball |
| - | - |
| Attributes | ![](http://thyrsi.com/t6/386/1539252592x1822611383.png) |
| Collaborator | Events & Actions |
| 精灵 | 笔直飞行 |
| | 与Spaceship相撞，爆炸&销毁自己 |

| Object name | Background |
| - | - |
| Attributes | ![](http://thyrsi.com/t6/386/1539260944x1822611431.png)
| Collaborator | Events & Actions |
| 背景 | 充当背景板 |