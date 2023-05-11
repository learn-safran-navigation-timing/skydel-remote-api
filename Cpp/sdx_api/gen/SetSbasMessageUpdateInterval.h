#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the SBAS message update interval.
    ///
    /// Name           Type Description
    /// -------------- ---- -----------------------------------------------------------------------------------------------
    /// Message        int  The message type.
    /// UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.
    ///

    class SetSbasMessageUpdateInterval;
    typedef std::shared_ptr<SetSbasMessageUpdateInterval> SetSbasMessageUpdateIntervalPtr;
    
    
    class SetSbasMessageUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasMessageUpdateInterval();

      SetSbasMessageUpdateInterval(int message, int updateInterval);

      static SetSbasMessageUpdateIntervalPtr create(int message, int updateInterval);
      static SetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** message ****
      int message() const;
      void setMessage(int message);


      // **** updateInterval ****
      int updateInterval() const;
      void setUpdateInterval(int updateInterval);
    };
    
  }
}

