package yitian.study.filter

import javax.servlet.Filter
import javax.servlet.FilterChain
import javax.servlet.FilterConfig
import javax.servlet.ServletException
import javax.servlet.ServletRequest
import javax.servlet.ServletResponse
import javax.servlet.annotation.WebFilter
import javax.servlet.annotation.WebInitParam
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

@WebFilter(
        filterName = 'CharEncodingFilter'
        , urlPatterns = ['/*']
        , initParams = [@WebInitParam(name = 'encoding', value = 'UTF-8')]
)
class CharEncodingFilter implements Filter {
    private String encoding

    @Override
    void init(FilterConfig filterConfig) throws ServletException {
        encoding = filterConfig.getInitParameter('encoding') ?: 'UTF-8'
    }

    @Override
    void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        def req = request as HttpServletRequest
        def resp = response as HttpServletResponse
        req.setCharacterEncoding(encoding)
        resp.setCharacterEncoding(encoding)
        chain.doFilter(req, resp)
    }

    @Override
    void destroy() {
    }
}
