#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import NMEA track file
    ///
    /// Name Type   Description
    /// ---- ------ --------------
    /// Path string NMEA file path
    ///

    class ImportNmeaTrack;
    typedef std::shared_ptr<ImportNmeaTrack> ImportNmeaTrackPtr;
    
    
    class ImportNmeaTrack : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportNmeaTrack();

      ImportNmeaTrack(const std::string& path);

      static ImportNmeaTrackPtr create(const std::string& path);
      static ImportNmeaTrackPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

