#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add/edit an antenna change.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------
    /// StartTime double Elapsed time in seconds since start of simulation.
    /// Antenna   string Antenna model name
    /// Id        string Unique identifier of the event
    ///

    class SetAntennaChange;
    typedef std::shared_ptr<SetAntennaChange> SetAntennaChangePtr;
    
    
    class SetAntennaChange : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetAntennaChange();

      SetAntennaChange(double startTime, const std::string& antenna, const std::string& id);

      static SetAntennaChangePtr create(double startTime, const std::string& antenna, const std::string& id);
      static SetAntennaChangePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** startTime ****
      double startTime() const;
      void setStartTime(double startTime);


      // **** antenna ****
      std::string antenna() const;
      void setAntenna(const std::string& antenna);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

