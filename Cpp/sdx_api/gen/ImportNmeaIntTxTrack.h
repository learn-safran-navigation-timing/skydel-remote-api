#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import NMEA interference track file
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Path string NMEA file path
    /// Id   string Transmitter unique identifier.
    ///

    class ImportNmeaIntTxTrack;
    typedef std::shared_ptr<ImportNmeaIntTxTrack> ImportNmeaIntTxTrackPtr;
    
    
    class ImportNmeaIntTxTrack : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportNmeaIntTxTrack();

      ImportNmeaIntTxTrack(const std::string& path, const std::string& id);

      static ImportNmeaIntTxTrackPtr create(const std::string& path, const std::string& id);
      static ImportNmeaIntTxTrackPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

