package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

/**
 * Created by simonppg on 21/03/18.
 */

public class MainScreen extends Activity {

    @Override protected void onCreate(Bundle savedInstanceState) {
        ListView items_list;
        String LOG_TAG = "MainScreen";
        final String[] items;

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_screen);

        Log.i(LOG_TAG, "Creating " + LOG_TAG);
        items = GameLibJNIWrapper.getTestsList();

        ArrayAdapter<String> adapter =
                new ArrayAdapter<>(this,
                        android.R.layout.simple_list_item_1, items);

        items_list = (ListView)findViewById(R.id.my_list);

        items_list.setAdapter(adapter);

        items_list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {

                Intent intent = new Intent(view.getContext(), GameActivity.class);
                intent.putExtra("position", position);
                startActivity(intent);
            }
        });
    }

    @Override protected void onPause() {
        super.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
    }
}