#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEphemerisTocOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// Offset int    Offset in sec. Accepted range is [-604800..604800].
    ///

    class GetEphemerisTocOffsetResult;
    typedef std::shared_ptr<GetEphemerisTocOffsetResult> GetEphemerisTocOffsetResultPtr;
    
    
    class GetEphemerisTocOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEphemerisTocOffsetResult();

      GetEphemerisTocOffsetResult(const std::string& system, int offset);

      GetEphemerisTocOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset);

      static GetEphemerisTocOffsetResultPtr create(const std::string& system, int offset);

      static GetEphemerisTocOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int offset);
      static GetEphemerisTocOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetEphemerisTocOffsetResult);
  }
}

