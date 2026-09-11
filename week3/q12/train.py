# q12/train.py
import torch
from torch import nn

torch.manual_seed(20260907)             
x = torch.linspace(-1, 1, 101).reshape(-1, 1)   
y = 3 * x - 1                         

model = nn.Linear(1, 1)                  
loss_fn = nn.MSELoss()                   
opt = torch.optim.SGD(model.parameters(), lr=0.1)

for _ in range(200):                    
    pred = model(x)                      # 前向：算出预测
    loss = loss_fn(pred, y)              # 算损失
    opt.zero_grad()                      # 清空梯度（不清会累加）
    loss.backward()                      # 反向传播求梯度
    opt.step()                           # 按梯度更新参数

model.eval()                             # 切到评估模式
with torch.no_grad():                    # 不计算梯度
    pred = model(x)
    final_loss = loss_fn(pred, y)        # 最终损失
print(f"final loss = {final_loss.item():.6f}")
print(f"weight = {model.weight.item():.6f}")
print(f"bias   = {model.bias.item():.6f}")