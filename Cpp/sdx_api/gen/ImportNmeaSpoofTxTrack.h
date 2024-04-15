#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import NMEA spoofer transmitter track file.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Path string NMEA file path.
    /// Id   string Transmitter unique identifier.
    ///

    class ImportNmeaSpoofTxTrack;
    typedef std::shared_ptr<ImportNmeaSpoofTxTrack> ImportNmeaSpoofTxTrackPtr;
    
    
    class ImportNmeaSpoofTxTrack : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportNmeaSpoofTxTrack();

      ImportNmeaSpoofTxTrack(const std::string& path, const std::string& id);

      static ImportNmeaSpoofTxTrackPtr create(const std::string& path, const std::string& id);
      static ImportNmeaSpoofTxTrackPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

