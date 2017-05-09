class WordMap extends SimpleMapModel {    
  HashMap words;
    
  WordMap() {
    words = new HashMap();
  }
    
  void addWord(String word, float f, float c, float p) {
    WordItem item = (WordItem) words.get(word);
    if (item == null) {
      item = new WordItem(word, f, c, p);
      words.put(word, item);
    }
    item.incrementSize();
  }
    
  void finishAdd() {
    items = new WordItem[words.size()];
    words.values().toArray(items);
  }
}