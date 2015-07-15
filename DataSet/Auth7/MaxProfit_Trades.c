/*
given a stream of quotes for a stock from the last trading day. Assume its already time sorted. Find the maximum amount of money you could have made on this stock by making at most N transactions. A buy and a sell is counted as one transaction. For parts N = 1, N = 2 and N = Inf and the generic solution for N = some number (open ended)
*/

bestTrades(prices, maxTrades) {
  // Build table of best selling point after time t
  bestSaleAfter = []
  int maxPrice = -Infinity;
  int maxT = -1
  for (t = prices.len - 1; t >= 0; t--) {
    bestSaleAfter[t] = { price: maxPrice, time: maxT }
    if prices[t] > maxPrice {
      maxPrice = prices[t]
      maxT = t
    }
  }
  
  // Build list of the best trades possible when buying at time t
  optimalTrades = []
  for (t = 0; t < prices.len -1; t++) {
    profit = bestSaleAfter[t].price - prices[t]
    if profit > 0 { // Omit unprofitable trades
      optimalTrades.push({ 
        profit: profit, 
        buyTime: t, 
        sellTime: bestSaleAfter[t].time 
      })
    }
  }
  
  // Sort to find the very best trades
  optimalTrades.sort(
  	lambda(tradeA, tradeB) : tradeA.profit < tradeB.profit
  )
  
  return optimalTrades[0:min(maxTrades, optimalTrades.len)]
}
