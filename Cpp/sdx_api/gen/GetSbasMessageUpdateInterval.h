#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the SBAS message update interval.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------
    /// Message int  The message type.
    ///

    class GetSbasMessageUpdateInterval;
    typedef std::shared_ptr<GetSbasMessageUpdateInterval> GetSbasMessageUpdateIntervalPtr;
    
    
    class GetSbasMessageUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasMessageUpdateInterval();

      GetSbasMessageUpdateInterval(int message);

      static GetSbasMessageUpdateIntervalPtr create(int message);
      static GetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** message ****
      int message() const;
      void setMessage(int message);
    };
    
  }
}

