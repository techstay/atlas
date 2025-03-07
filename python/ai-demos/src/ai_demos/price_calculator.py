# %%
from decimal import Decimal, getcontext


def show_token_price_in_usd(
    input_pkt_in_cny: float, output_pkt_in_cny: float
) -> tuple[str, str]:
    "ptk: per 1k tokens price"

    getcontext().prec = 5
    usd_cny_rate = Decimal("7.2")
    input_price_pkt_in_usd = Decimal(str(input_pkt_in_cny)) / usd_cny_rate / 1000
    output_price_pkt_in_usd = Decimal(str(output_pkt_in_cny)) / usd_cny_rate / 1000
    return f"{input_price_pkt_in_usd:f}", f"{output_price_pkt_in_usd:f}"


show_token_price_in_usd(
    0.004,
    0.016,
)

# %%
