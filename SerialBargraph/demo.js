function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}
const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");
  

const port = new SerialPort('/dev/cu.SLAB_USBtoUART',{
    baudRate: 115200
})

async function run(){
    port.on('error', function(err){
    console.log('Error: ', err.message)
    })

    port.write('0\n', function(err){
    if(err){
        return console.log('Error on write: ', err.message)
    }
        console.log('blank')
    })
    while (true){
        for (let i =1; i < 25; i++){
            let amount = `${i}\n`;
            port.write(amount, function(err){
                if(err){
                    return console.log('Error on write: ', err.message)
                }
                console.log(amount)
            })
            await sleep(50);
        }
        for (let i =24; i >=0; i--){
            let amount = `${i}\n`;
            port.write(amount, function(err){
                if(err){
                    return console.log('Error on write: ', err.message)
                }
                console.log(amount)
            })
            await sleep(50);
        }
    }
    }
run();
