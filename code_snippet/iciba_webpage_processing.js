let allLists = document.querySelectorAll("li");
let outerBox;
allLists.forEach(l=>{
    if(l.innerText=="柯林斯高阶英汉双解学习词典")
    {
        
        outerBox=l.parentElement.parentElement;
    }
});
let soundELe=outerBox.querySelectorAll(".icon-sound");
soundELe.forEach(s=>{
    try{
        s.parentElement.nextElementSibling.remove();
        // 增加我的翻译  及其 例句翻译 节点
        let transArr=["我的翻译:","例句翻译:"];
        transArr.forEach(t=>{
            let newP=document.createElement("p");
            newP.innerText=t;
            s.parentElement.append(newP)
        })
        
    }
    catch(e)
    {

    }
   
});
copy(outerBox);