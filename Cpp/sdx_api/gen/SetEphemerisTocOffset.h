#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the ephemeris TOC offset in seconds relative to the ephemeris update time.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Offset int    Offset in sec. Accepted range is [-604800..604800].
    ///

    class SetEphemerisTocOffset;
    typedef std::shared_ptr<SetEphemerisTocOffset> SetEphemerisTocOffsetPtr;
    
    
    class SetEphemerisTocOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetEphemerisTocOffset();

      SetEphemerisTocOffset(const std::string& system, int offset);

      static SetEphemerisTocOffsetPtr create(const std::string& system, int offset);
      static SetEphemerisTocOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    
  }
}

