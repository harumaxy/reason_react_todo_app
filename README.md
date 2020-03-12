# Reason react starter

# ReasonReact TodoApp
ReasonReactを使うための練習。

`useReducer` Hooksによる  
Reduxを使わないRedux的なアーキテクチャ。


# Sassを使う

```bash
yarn add --dev node-sass sass-loader
```

```js
// webpack.config.js
module.exports = {
  module: {
    rules: [
      {
        test: /\.s[ac]ss$/i,
        use: ["style-loader", "css-loader", "sass-loader"]
      }
    ],
  },
};
```

# useReducer を使うときの注意

Component内に`reducer`関数を定義すると、再レンダリングするたびに <br>
新しい関数が作成される。

`reducer`関数が実行中に再レンダリングされると、同じ`action`を2回処理してしまうことなどがある。

- topレベルにlet定義する。
- useCallbackを使う。

など、何度も作り直されないようにする仕組みが必要。