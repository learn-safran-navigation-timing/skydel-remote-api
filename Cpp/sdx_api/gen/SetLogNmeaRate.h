#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Rate logging of NMEA data
    ///
    /// Name Type Description
    /// ---- ---- ------------------------------
    /// Rate int  Accepted rates are 1 and 10 Hz
    ///

    class SetLogNmeaRate;
    typedef std::shared_ptr<SetLogNmeaRate> SetLogNmeaRatePtr;
    
    
    class SetLogNmeaRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetLogNmeaRate();

      SetLogNmeaRate(int rate);

      static SetLogNmeaRatePtr create(int rate);
      static SetLogNmeaRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    
  }
}

