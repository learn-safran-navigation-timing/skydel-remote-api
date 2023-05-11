#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// USE AT YOUR OWN RISKS. Set the RF Gain of the SDR
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------
    /// Output int    Output index (zero based)
    /// Gain   double RF Gain of the SDR, in dB. Default value is 0. Only supported for USRP.
    ///

    class SetRfGain;
    typedef std::shared_ptr<SetRfGain> SetRfGainPtr;
    
    
    class SetRfGain : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetRfGain();

      SetRfGain(int output, double gain);

      static SetRfGainPtr create(int output, double gain);
      static SetRfGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** gain ****
      double gain() const;
      void setGain(double gain);
    };
    
  }
}

