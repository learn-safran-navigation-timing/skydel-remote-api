#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAntennaChange.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------
    /// StartTime double Elapsed time in seconds since start of simulation.
    /// Antenna   string Antenna model name
    /// Id        string Unique identifier of the event
    ///

    class GetAntennaChangeResult;
    typedef std::shared_ptr<GetAntennaChangeResult> GetAntennaChangeResultPtr;
    
    
    class GetAntennaChangeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAntennaChangeResult();

      GetAntennaChangeResult(double startTime, const std::string& antenna, const std::string& id);

      GetAntennaChangeResult(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id);

      static GetAntennaChangeResultPtr create(double startTime, const std::string& antenna, const std::string& id);

      static GetAntennaChangeResultPtr create(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id);
      static GetAntennaChangeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAntennaChangeResult);
  }
}

