#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsSignalEnabled is deprecated since 21.3. You may use IsSignalEnabledForSV.
    /// 
    /// Tells if the signal is enabled or disabled. See IsSignalEnabled description for allowed signals.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Signal string Signal key - see command description for possible values
    ///

    class IsSignalEnabled;
    typedef std::shared_ptr<IsSignalEnabled> IsSignalEnabledPtr;
    
    
    class IsSignalEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalEnabled();

      IsSignalEnabled(int prn, const std::string& signal);
  
      static IsSignalEnabledPtr create(int prn, const std::string& signal);
      static IsSignalEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

