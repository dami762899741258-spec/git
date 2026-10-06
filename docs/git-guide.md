# Git / GitHub 使用手册 —— 以 FOC 3.0t 工程为例

> 面向第一次用 Git 的人。全程用你自己工程里的真实文件举例。

---

## 0. 先搞懂 4 个地方（30 秒）

| 名字 | 是什么 | 在你这里对应 |
|---|---|---|
| **工作区** | 你正在编辑的文件 | `C:\Users\xiao\Desktop\git\FOC-3.0t\MDK-ARM\foc_loop.c` |
| **暂存区** | 「这次要提交哪些改动」的篮子 | VS Code 里点了 `+` 的文件 |
| **本地仓库** | 提交历史，存在 `.git` 隐藏文件夹 | `C:\Users\xiao\Desktop\git\.git` |
| **远端仓库** | GitHub 上的备份 | github.com/dami762899741258-spec/git |

**每次改代码只有 4 步：改 → 暂存 → 提交 → 推送。**

---

## 1. 一次性准备（已经帮你做好了）

- ✅ 仓库建在 `C:\Users\xiao\Desktop\git`，分支 `main`
- ✅ FOC 3.0t 工程已导入：`C:\Users\xiao\Desktop\git\FOC-3.0t\`
- ✅ `.gitignore` 已配好：编译产物（`MDK-ARM/build/`、`MDK-ARM/FOC-3.0t/`、`*.o`、`*.axf`…）
  全部排除，仓库从 **90.3 MB 瘦身到 4.35 MB**
- ✅ `.gitattributes` 已配好，避免 Keil 和 VS Code 互相改换行符导致「整个文件都变红」
- ⚠️ **旧的工程目录 `C:\Users\xiao\Desktop\FOC板子\FOC-3.0t` 还在**，
  确认新位置能正常编译后建议删掉，以后**只在仓库里改代码**，否则两边会分叉

### 还需要你装的 VS Code 插件（3 个，全免费）

按 `Ctrl+Shift+X` 打开扩展面板，搜名字装：

| 插件 | 搜索名 | 干什么用 |
|---|---|---|
| **GitLens** | `GitLens` | 光标停在任意一行，直接看到这行是谁、哪次提交改的 |
| **Git Graph** | `Git Graph` | 画出一张提交历史图，一眼看清每次提交 |
| **GitHub Pull Requests** | `GitHub Pull Requests` | 官方插件，能在 VS Code 里登录 GitHub、直接在浏览器打开仓库 |

> Git 本身**不需要插件**，VS Code 内置了。上面 3 个只是让历史更好看。
> 你已有的 **EIDE**（`cl.eide`）负责编译烧录，和 Git 互不干扰。

---

## 2. 日常循环（5 步走）

### 第 0 步：用「仓库根目录」打开 VS Code

`文件 → 打开文件夹 → C:\Users\xiao\Desktop\git`

> ⚠️ 要打开的是 **git 这个文件夹**，不是里面的 `FOC-3.0t`。
> 打开对了，左下角状态栏才会显示 `main` 分支名。

---

### 场景 A：调好了电流环 PI 参数（改已有文件）

假设你把 `foc_loop.c` 里的 `KP`/`KI` 从 3.0 调到 5.0 并验证通过。

1. 按 **`Ctrl+Shift+G`** 打开左侧「源代码管理」面板
2. 会看到一行：

   ```
   M  FOC-3.0t/MDK-ARM/foc_loop.c
   ```

   - `M` = Modified（改过）
   - `U` = Untracked（新文件，Git 还不认识）
   - `D` = Deleted（删了）

3. **点一下文件名** → 右边弹出红绿对比图，红的是删掉的，绿的是你新加的。
   **提交前一定要看一眼**，防止夹带了调试用的 `printf`。
4. 点文件名右边的 **`+`**（暂存更改）→ 文件移到上面「暂存的更改」区
5. 在上方输入框写提交信息，例如：

   ```
   tune: 电流环 KP 3.0→5.0，阶跃响应无超调
   ```

6. 按 **`Ctrl+Enter`** 提交 → 改动从列表消失，说明已经存进本地仓库了
7. 点左下角状态栏的 **`同步更改`**（或 `↑` 图标）→ 推送到 GitHub

> 推送前 VS Code 可能弹窗要求登录 GitHub，点允许即可（用浏览器授权）。

---

### 场景 B：修完一个 ADC 采样偏置的 bug

你发现 `bsp_adc.c` 里电流零漂补偿写错了，改完并实测正常。

1. `Ctrl+Shift+G` → 看到 `M FOC-3.0t/MDK-ARM/bsp_adc.c`
2. 填：

   ```
   fix: 修正 bsp_adc 电流零漂补偿符号错误导致 q 轴反馈反向
   ```

3. `Ctrl+Enter` 提交 → `同步更改` 推送

**关键习惯：改多少提交多少。** 一个 bug 一次提交，
以后翻历史时能精确找到「是哪次改动引入了问题」。

---

### 场景 C：新增一个文件（比如加个观测器）

你新建了 `foc_observer.c` 和 `foc_observer.h`。

1. `Ctrl+Shift+G` → 它们在 **「更改」** 区，前面是 `U`
2. 两个文件都点 `+` 暂存
3. 填：

   ```
   feat: 新增滑模观测器 foc_observer，暂未接入主循环
   ```

4. 提交 → 推送

> 新文件只有被 `git add` 过，Git 才会开始跟踪它。

---

### 场景 D：一次调试跑通了，想标记成里程碑

调了三天，电流环终于闭环稳定。除了正常提交，还可以**打标签**：

在 VS Code 终端（`` Ctrl+` ``）里：

```powershell
git tag -a v0.1-current-loop -m "电流环闭环稳定，阶跃响应 2ms"
git push origin v0.1-current-loop
```

之后在 GitHub 的 `Tags` 里就能看到这个里程碑，随时能下载当时的完整代码。
这就是「分期完成」最实用的做法：**每个阶段留一个 tag**。

---

## 3. 提交信息怎么写（照抄这些格式）

格式就一句话：**`类型: 干了什么`**

| 类型 | 什么时候用 | FOC 工程里的真实例子 |
|---|---|---|
| `feat` | 加新功能 | `feat: 新增 foc_svpwm 五段式调制` |
| `fix` | 修 bug | `fix: 修复 bsp_protect 过流阈值判断用了大于号` |
| `tune` | 只调参数 | `tune: 速度环 KI 8.0→12.0，消除稳态误差` |
| `refactor` | 改结构不改功能 | `refactor: foc_math 的 Park 变换改为内联函数` |
| `docs` | 只改注释/文档 | `docs: 补充 foc_state 状态机注释` |
| `chore` | 杂项 | `chore: 更新 .gitignore 忽略 EIDE 临时文件` |

**反面例子**（以后自己看不懂）：
`更新`、`改了一下`、`111`、`asdf`

---

## 4. 在 GitHub 上查看你的提交

打开 https://github.com/dami762899741258-spec/git

| 想看什么 | 点哪里 |
|---|---|
| 最新的代码 | 首页中间的文件列表 → 点 `FOC-3.0t` → `MDK-ARM` → 点 `foc_loop.c` |
| **某次改了什么** | 点上方 **`commits`**（提交记录）→ 点任意一条提交 |
| 这个文件的历史 | 打开文件后，右上角 **`History`** |
| **每一行是谁改的** | 打开文件后，右上角 **`Blame`** |
| 下载整个工程 | 绿色 **`Code`** 按钮 → `Download ZIP` |
| 里程碑 | **`Tags`** |

> 手机上用 GitHub App 或浏览器也能看，改完代码在手机上翻一眼很方便。

---

## 5. 常用操作速查

在 VS Code 里按 **`Ctrl+Shift+P`** 打开命令面板，输入 `Git` 就能看到全部命令。

| 我想… | 怎么做 |
|---|---|
| 看这次改了什么 | `Ctrl+Shift+G` → 点文件名 |
| 撤销某个文件的改动 | 源代码管理面板里，文件名右边点 **`↩`**（放弃更改） |
| 提交信息写错了 | 终端执行 `git commit --amend -m "正确信息"`（**没推送前**才能用） |
| 看历史 | 装 Git Graph 后，左下角点 `Git Graph` |
| 回退到某个版本 | 终端 `git revert <提交号>`（安全，会生成一条反向提交） |
| 看当前状态 | 终端 `git status` |

---

## 6. 五个必踩的坑（都已经帮你处理了）

1. **编译产物会被提交进去** —— 你的 `MDK-ARM/` 一度有 90 MB，
   其中 85 MB 是 `.o`/`.axf`/`build/`。已在 `.gitignore` 里排除，
   **以后新建 Keil Target 时，记得把新的输出目录名加进 `MDK-ARM/.gitignore`**。
2. **换行符打架** —— Keil 存 CRLF，VS Code 默认 LF，不统一会让每次提交都显示
   「整个文件都改了」。已用 `.gitattributes` 固定。
3. **代理** —— 你本机走 `127.0.0.1:7897`。Git 已配好；如果 VS Code 登录 GitHub
   转圈，就在设置里搜 `http.proxy` 填 `http://127.0.0.1:7897`。
4. **路径里有空格和中文** —— 你老工程路径是 `FOC板子\FOC-3.0t`（有中文、有空格），
   Keil 偶尔会出问题。新位置 `Desktop\git\FOC-3.0t` 是纯英文，更稳。
5. **HAL 库没进仓库** —— 你的工程用绝对路径 `E:/STM32CubeMX/STM32Cube_FW_G4_V1.6.3`
   引用 HAL 库，所以**换电脑克隆后需要装同版本 CubeMX 包**才能编译。
   想彻底解决：CubeMX → `Project Manager → Code Generator` → 勾选
   `Copy only the necessary library files` 重新生成。

---

## 7. 一句话总结

> 每改完一个能跑通的小功能，就 `Ctrl+Shift+G` → 写一句人话 → `Ctrl+Enter` → 同步。
> 一天推 3～5 次都不嫌多，**Git 的价值在于历史足够细**。
