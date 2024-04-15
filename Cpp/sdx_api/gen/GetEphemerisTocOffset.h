#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ephemeris TOC offset in seconds relative to the ephemeris update time.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    ///

    class GetEphemerisTocOffset;
    typedef std::shared_ptr<GetEphemerisTocOffset> GetEphemerisTocOffsetPtr;
    
    
    class GetEphemerisTocOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEphemerisTocOffset();

      GetEphemerisTocOffset(const std::string& system);

      static GetEphemerisTocOffsetPtr create(const std::string& system);
      static GetEphemerisTocOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

