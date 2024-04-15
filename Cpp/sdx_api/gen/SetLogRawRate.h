#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Rate logging of raw data
    ///
    /// Name Type Description
    /// ---- ---- --------------------------------------
    /// Rate int  Accepted rates are 10, 100 and 1000 Hz
    ///

    class SetLogRawRate;
    typedef std::shared_ptr<SetLogRawRate> SetLogRawRatePtr;
    
    
    class SetLogRawRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetLogRawRate();

      SetLogRawRate(int rate);

      static SetLogRawRatePtr create(int rate);
      static SetLogRawRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    
  }
}

