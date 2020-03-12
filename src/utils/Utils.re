let valueFromEvent = e =>
  (e |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;