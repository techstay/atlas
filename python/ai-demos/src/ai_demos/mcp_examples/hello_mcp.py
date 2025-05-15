from httpx import AsyncClient
from mcp.server import FastMCP

mcp = FastMCP("hello_mcp")


@mcp.tool()
def greet(name: str):
    """
    Return a greeting message for the given name.

    Args:
       name (str): The name of the person to greet.

    Returns:
        str: A greeting message.
    """
    return f"Hello, {name}"


@mcp.tool()
async def hitokoto():
    """
    Return a hitokoto message.

    Returns:
        str: A hitokoto message.
    """
    base_url = "https://international.v1.hitokoto.cn"
    async with AsyncClient() as client:
        resp = await client.get(
            base_url,
            params={
                "encode": "json",
            },
        )
    return f"{resp.json()['hitokoto']} -- {resp.json()['from']}"


r"""You can use the inspector to test this mcp. If you run this mcp server using
stdio transport, you should change separator to `/` instead of `\` on Windows.

If you met issues of inspector, you can try open inspector url in vscode simple browser.
see also:
https://stackoverflow.com/questions/79582846/the-python-mcp-server-with-stdio-transport-throws-an-error-sse-connection-not
"""


# default entry point is http://127.0.0.1:8000/sse
if __name__ == "__main__":
    mcp.run(transport="sse")
