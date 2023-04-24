def name = params['name'] ?: '易天'


html.html {
    head {
        title('主页')
        link(rel: 'stylesheet', src: 'site.css')
    }
    body {
        h1 "${name} 你好"

        form(method: 'get', action: 'index.groovy') {
            label(for: 'name', value: '请输入名称')
            input(id: 'name', type: 'text', name: 'name')
            input(type: 'submit', value: '提交')
        }

    }
}